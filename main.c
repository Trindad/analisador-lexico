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
		expressoes[i].l1.s = malloc(nstate*sizeof expressoes[i].l1.s[0]);
	}

	// if(match(startdstate(expressoes[2].maquina, &expressoes[2].l1), "mauriciocinelli+2@gmail.com", &(expressoes[2].l1))) {
	// 	printf("%s\n", "mauriciocinelli+2@gmail.com");
	// }

	// if(match(startdstate(expressoes[31].maquina, &expressoes[31].l1), "<<", &(expressoes[31].l1))) {
	// 	printf("%s\n", "<<");
	// }

	// if(match(startdstate(expressoes[2].maquina, &expressoes[2].l1), "mauriciocinelli+2@gmail.com", &(expressoes[2].l1))) {
	// 	printf("%s\n", "mauriciocinelli+2@gmail.com");
	// }

	/**
	 * Roda máquinas 
	 * Descarta as máquinas que são inválidas
	 */
	int cont = 0,k = 0,reconheceu = 0;

	char *buff = (char*) malloc (sizeof(char) * MAX+1);
	Token *tokens = (Token*) malloc (sizeof(Token) * MAX+1);//tabela de tokens

	if (buff == NULL ||  tokens == NULL) {
		exit(1);
	}

	char c = proximoCaractere(buffer),cAnt = '\0';

	int prioridadeant = MAX;
	int maquina = 0;

	while(c != EOF) {
		
		printf("%c %d\n",c,cont );
		if (c != '\n' && c != ' ' && c != '\t' && cAnt != EOF) {
		 	
		 	buff[cont] = c;
		}

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

		if ( cont >= 1 && (c == ' ' || c == '\n' || c == '\t') && ( buff[0] != ' ' || buff[0] == '\n' || buff[0] == '\t')  )
		{
			printf("\ncaso 1 buff '%s' maq %d rec %d prio %d\n",buff,maquina,reconheceu,prioridadeant );

			memset(buff,'\0',MAX);//reset no buffer
			
			cont = 0;
			prioridadeant = MAX;
			maquina = 0;

			c = proximoCaractere(buffer);
			
			if (c == '\n' || c == ' ' || c == '\t')
			{
				cont--;
			}
		}
		else if ( cont >= 1 && (reconheceu == N && prioridadeant != MAX))
		{
			printf("\ncaso 2 buff '%s' maq %d rec %d prio %d\n",buff,maquina,reconheceu,prioridadeant );
			
			c = buff[cont];

			memset(buff,'\0',MAX);//reset no buffer

			cont = 0;

			prioridadeant = MAX;
			maquina = 0;

		/*	if (c == '\n' || c == ' ' || c == '\t')
			{
				cont--;
			}*/
		}
		else
		{
			c = proximoCaractere(buffer);
			
			// printf("-%c %d %c\n", c, cont,cAnt);
			cont++;

			if ( (c == '\n' || c == ' ' || c == '\t') && cont == 0)
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
			cAnt = c;
			c = '\n';
			cont++;
			buff[cont] = '\0';
			cont--;
			// printf("serio %d '%s' %c %c\n",cont,buff,c,cAnt);
		}

		reconheceu = 0;	
	}
	
	fclose(arquivo);

	return 0;
}
