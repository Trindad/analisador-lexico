#include "thompson.h"
#include "analisador.h"

int main(int argc, char **argv)
{
	int i;
	char *post;
	State *start;

	Expressao *expressoes = criaExpressoes();

	FILE *arquivo = abreArquivoFonte("example.jusm");
	Buffer *buffer = criaBuffer(arquivo);

	for (i = 0; i < N; i++) {
		post = re2post(expressoes[i].expressao);

		if(post == NULL){
			fprintf(stderr, "bad regexp %s\n", expressoes[i].expressao);
			return 1;
		}

		start = post2nfa(post);

		if(start == NULL){
			fprintf(stderr, "error in post2nfa %s\n", post);
			return 1;
		}

		expressoes[i].maquina = start;
		expressoes[i].l1.s = malloc (nstate*sizeof expressoes[i].l1.s[0]);

		if (expressoes[i].l1.s == NULL)
		{
			exit(1);
		}
	}


	if(match(startdstate(expressoes[1].maquina, &expressoes[1].l1), "2,", &(expressoes[1].l1))) {
		printf("%s\n", "2,");
	}
	else
	{
		printf("não reconheceu\n");
	}

	/**
	 * Roda máquinas 
	 * Descarta as máquinas que são inválidas
	 */
	int cont = 0,k = 0,reconheceu = 0;

	char *buff = (char*) malloc (sizeof(char) * MAX+1);

	if (buff == NULL)
	{
		exit(1);
	}
	Token *tokens = (Token*) malloc (sizeof(Token) * MAX+1);//tabela de tokens

	if (tokens == NULL) {
		exit(1);
	}

	int it = 0;

	for (it = 0; it <= MAX; it++)
	{
		buff[it] = '\0';
	}

	char c = proximoCaractere(buffer),cAnt = '\0';

	int prioridadeant = MAX;
	int maquina = 0;

	while(c != EOF) {
		
		// printf("'%s' %c %d\n",buff,c,cont );
		if (c != '\n' && c != ' ' && c != '\t' && cAnt != EOF && cont >= 0) {
		 	
		 	buff[cont] = c;
		}

		if ( ( buff[0] != ' ' || buff[0] == '\n' || buff[0] != '\t')  && cont >= 0)
		{
			for (k = 0; k < N; k++)
			{
				DState *start = startdstate(expressoes[k].maquina, &expressoes[k].l1);
				List *l1 = &(expressoes[k].l1);

				DState *d, *next;
				int j = 0, i = 0, w = 0;
				
				d = start;
				for(w = 0; w < cont; w++) {

					j = buff[w] & 0xFF;

					if((next = d->next[j]) == NULL) {
						next = nextstate(d, j, l1);
					}

					d = next;
				}

				if (ismatch(&d->l))
				{
					// printf("\nreconheceu '%s' token %d %d %d\n",buff, k, prioridadeant,expressoes[k].prioridade);
					if (expressoes[k].prioridade <  prioridadeant)
					{
						prioridadeant = expressoes[k].prioridade;

						maquina = k;
					}
				}
				else
				{
					reconheceu++;
				}
			}
		}

		if ( cont >= 1 && (c == ' ' || c == '\n' || c == '\t') && ( buff[0] != ' ' || buff[0] == '\n' || buff[0] != '\t')  )
		{
			printf("\ncaso 1 buff '%s' maq %d rec %d prio %d\n",buff,maquina,reconheceu,prioridadeant);

			for (it = 0; it <= MAX; it++)
			{
				buff[it] = '\0';
			}
			
			cont = 0;
			prioridadeant = MAX;
			maquina = 0;

			c = proximoCaractere(buffer);
			
			if (c == '\n' || c == ' ' || c == '\t' || c == EOF)
			{
				// printf("cont %d\n",cont);
				cont--;
			}
		}
		else if ( cont >= 1 && (reconheceu == N && prioridadeant != MAX) && ( buff[cont] != ',' && maquina != 1) )
		{
			printf("\ncaso 2 buff '%s' maq %d rec %d prio %d %d %c\n",buff,maquina,reconheceu,prioridadeant,cont,buff[cont]);
			
			c = buff[cont];
			
			for (it = 0; it <= MAX; it++)
			{
				buff[it] = '\0';
			}

			cont = 0;

			prioridadeant = MAX;
			maquina = 0;
		}
		else
		{
			c = proximoCaractere(buffer);
			//printf("%c\n",c );
			// printf("-%c %d %c\n", c, cont,cAnt);
			cont++;

			if ( (c == '\n' || c == ' ' || c == '\t') && cont == 0 || c == EOF)
			{
				cont--;
			}
		}
		
		if (cAnt == EOF)
		{
			break;
		}

		if (c == EOF && cont >= 1)
		{
			// printf("serio %d '%s' %c %c\n",cont,buff,c,cAnt);
			cAnt = c;
			c = '\n';
			cont++;
			buff[cont] = '\0';
			cont--;
		}

		reconheceu = 0;	
	}

	fclose(arquivo);
	free(buff);
	free(buffer);
	free(tokens);

	for (i = 0; i < N; i++)
	{
		free(expressoes[i].l1.s);
	}
	free(expressoes);

	return 0;
}
