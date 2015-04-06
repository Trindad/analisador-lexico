#include "thompson.h"
#include "analisador.h"

int main(int argc, char **argv)
{
	int i;
	char *post;
	State *start;

	int ntokens = 0;
	int nSimbolos = 0;

	Expressao *expressoes = criaExpressoes();

	if (expressoes == NULL)
	{
		exit(1);
	}

	Token tabela_tokens[MAX];
	Simbolo tabela_simbolos[MAX];

	for (i = 0; i < MAX; i++) {
		tabela_simbolos[i].nome = NULL;
		tabela_tokens[i].str = NULL;
	}

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


	// if(match(startdstate(expressoes[1].maquina, &expressoes[1].l1), "2,", &(expressoes[1].l1))) {
	// 	printf("%s\n", "2,");
	// }
	// else
	// {
	// 	printf("não reconheceu\n");
	// }

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

	int it = 0;

	for (it = 0; it <= MAX; it++)
	{
		buff[it] = '\0';
	}

	char c = proximoCaractere(buffer),cAnt = '\0';

	int prioridadeant = MAX;
	int maquina = -1,asp = 0,linha = 1,coluna = 0, colunaAnterior = -1;

	while(c != EOF) {
		
		
		if (c == '\"')
		{
			asp++;
		}

		if (c == '\n') {
			linha++;
			colunaAnterior = coluna;
			coluna = 0;
		}
		else if (c != '\n')
		{
			coluna++;
		}
		// printf("caractere %c coluna %d linha %d\n",c,coluna,linha );
		// tratamento de erro léxico
		if (asp == 1 && c == '\n' )
		{
			panico(1,linha,coluna,buff);
		}

		if (c != '\n' && (c == ' ' && asp >= 1) && c != '\t' && cAnt != EOF && cont >= 0) {
		 	
		 	buff[cont] = c;
		}
		else if (c != '\n' && c != ' ' && c != '\t' && cAnt != EOF && cont >= 0) {
		 	
		 	buff[cont] = c;
		}

		// printf("-------------------------\n'%s' %c %d\n",buff,c,cont );

		if ( ( buff[0] != ' ' || buff[0] == '\n' || buff[0] != '\t')  && cont >= 0)
		{
			for (k = 0; k < N; k++)
			{
				DState *start = startdstate(expressoes[k].maquina, &expressoes[k].l1);
				List *l1 = &(expressoes[k].l1);

				DState *d, *next;
				int j = 0, i = 0, w = 0;
				
				d = start;
				int length = strlen(buff);
				for(w = 0; w < length; w++) {

					j = buff[w] & 0xFF;

					if((next = d->next[j]) == NULL) {
						next = nextstate(d, j, l1);
					}

					d = next;
				}

				if (ismatch(&d->l))
				{
					// printf("\nreconheceu '%s' token %d %d %d\n",buff, k, prioridadeant,expressoes[k].prioridade);
					if (expressoes[k].prioridade <=  prioridadeant)
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

		// printf("cont %d reconheceu %d, prioANterior %d maq %d asp %d bfc %c\n", cont, reconheceu, prioridadeant, maquina, asp, buff[cont]);

		if ( cont >= 1 && (c == ' ' || c == '\n' || c == '\t') && ( buff[0] != ' ' || buff[0] == '\n' || buff[0] != '\t')  && ( asp == 0 || asp == 2 ) )
		{
			if (maquina == -1 && strlen(buff) > 0) {
				if (c == '\n') {
					panico(2, linha - 1, colunaAnterior - cont, buff);
				} else {
					panico(2, linha, coluna - cont - 1,buff);
				}

				for (it = 0; it <= MAX; it++)
				{
					buff[it] = '\0';
				}
				
				cont = 0;
				prioridadeant = MAX;
				maquina = -1;
				asp = 0;

				c = proximoCaractere(buffer);
				
				if (c == '\n' || c == ' ' || c == '\t' || c == EOF)
				{
					// printf("cont %d\n",cont);
					cont--;
				}
				continue;
			}

			// printf("\ncaso 1 buff '%s' maq %d rec %d prio %d %d\n",buff,maquina,reconheceu,prioridadeant,asp);

			if (strlen(buff)) {
				int id = -1;
				// vai pra tabela de simbolo
				if (expressoes[maquina].tsimbolo == 1) {
					int indiceSimbolo = encontraSimbolo(tabela_simbolos, buff);
					if (indiceSimbolo == -1) {
						tabela_simbolos[nSimbolos].nome = malloc(sizeof(char) * (strlen(buff) + 2));

						if (tabela_simbolos[nSimbolos].nome == NULL	)
						{
							printf("Erro na alocação de memória.\n");
							exit(1);
						}

						strcpy(tabela_simbolos[nSimbolos].nome, buff);
						tabela_simbolos[nSimbolos].nome[cont] = '\0';
						tabela_simbolos[nSimbolos].cod = nSimbolos + 1;
						tabela_simbolos[nSimbolos].categoria = 1;

						// printf("anterior %s, %s\n", tabela_tokens[ntokens-1].str, buff);

						if ( strcmp(tabela_tokens[ntokens-1].str,"string") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 1;
						}
						else if ( strcmp(tabela_tokens[ntokens-1].str,"int") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 2;
						}
						else if ( strcmp(tabela_tokens[ntokens-1].str,"float") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 3;
						}
						else
						{
							tabela_simbolos[nSimbolos].tipo = -1;
							panico(3,linha,coluna - cont,buff);
						}

						id = nSimbolos;
						indiceSimbolo = nSimbolos;
						nSimbolos++;

					} else {
						id = indiceSimbolo;
					}
				}

				tabela_tokens[ntokens].str = malloc(sizeof(char) * (strlen(buff) + 2));
				strncpy(tabela_tokens[ntokens].str, buff, cont);
				tabela_tokens[ntokens].str[cont] = '\0';
				tabela_tokens[ntokens].tipo = expressoes[maquina].tipo;
				tabela_tokens[ntokens].id = id;
				tabela_tokens[ntokens].cod = ntokens + 1;
				tabela_tokens[ntokens].linha = linha;
				// tabela_tokens[ntokens].coluna
				
				ntokens++;
			}

			for (it = 0; it <= MAX; it++)
			{
				buff[it] = '\0';
			}
			
			cont = 0;
			prioridadeant = MAX;
			maquina = -1;
			asp = 0;

			c = proximoCaractere(buffer);
			
			if (c == '\n' || c == ' ' || c == '\t' || c == EOF)
			{
				// printf("cont %d\n",cont);
				cont--;
			}
		}
		else if ( cont >= 1 && (reconheceu == N && prioridadeant != MAX) && ( asp == 0 || asp == 2) )
		{
			// printf("\ncaso 2 buff '%s' maq %d rec %d prio %d %d %c %d\n",buff,maquina,reconheceu,prioridadeant,cont,buff[cont],asp);

			if (maquina == 32 && buff[cont - 1] == ',') {
				buff[cont-1] = '\0';
			}

			if (strlen(buff)) {
				int id = -1;
				// vai pra tabela de simbolo
				if (expressoes[maquina].tsimbolo == 1) {
					int indiceSimbolo = encontraSimbolo(tabela_simbolos, buff);
					if (indiceSimbolo == -1) {
						tabela_simbolos[nSimbolos].nome = (char *)malloc(sizeof(char) * (strlen(buff)+2));

						if (tabela_simbolos[nSimbolos].nome == NULL)
						{
							exit(1);
						}

						strncpy(tabela_simbolos[nSimbolos].nome, buff, cont);
						tabela_simbolos[nSimbolos].nome[cont] = '\0';
						tabela_simbolos[nSimbolos].cod = nSimbolos + 1;
						tabela_simbolos[nSimbolos].categoria = 1;

						// printf("anterior %s, %s\n", tabela_tokens[ntokens-1].str, buff);

						if ( strcmp(tabela_tokens[ntokens-1].str,"string") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 1;
						}
						else if ( strcmp(tabela_tokens[ntokens-1].str,"int") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 2;
						}
						else if ( strcmp(tabela_tokens[ntokens-1].str,"float") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 3;
						}
						else
						{
							tabela_simbolos[nSimbolos].tipo = -1;
							panico(3,linha,coluna - cont,buff);
						}

						id = nSimbolos;
						indiceSimbolo = nSimbolos;
						nSimbolos++;

					} else {
						id = indiceSimbolo;
					}
				}

				tabela_tokens[ntokens].str = (char*) malloc(sizeof(char) * (strlen(buff) + 2));

				if (tabela_tokens[ntokens].str == NULL)
				{
					exit(1);
				}
				strncpy(tabela_tokens[ntokens].str, buff, cont);
				tabela_tokens[ntokens].str[cont] = '\0';
				tabela_tokens[ntokens].tipo = expressoes[maquina].tipo;
				tabela_tokens[ntokens].id = id;
				tabela_tokens[ntokens].cod = ntokens + 1;
				tabela_tokens[ntokens].linha = linha;
				// tabela_tokens[ntokens].coluna
				
				ntokens++;
			}
			
			c = buff[cont];
			
			for (it = 0; it <= MAX; it++)
			{
				buff[it] = '\0';
			}

			cont = 0;

			prioridadeant = MAX;
			maquina = -1;
			asp = 0;
		}
		else if ( cont >= 1 && (reconheceu == N && prioridadeant != MAX) && ( buff[cont - 1] == ',' && maquina == 32) && ( asp == 0 || asp == 2) )
		{
			// printf("\ncaso 3 buff '%s' maq %d rec %d prio %d %d %c %d\n",buff,maquina,reconheceu,prioridadeant,cont,buff[cont],asp);
			


			if (maquina == 32 && buff[cont - 1] == ',') {
				buff[cont-1] = '\0';
			}

			if (strlen(buff)) {
				int id = -1;
				// vai pra tabela de simbolo
				if (expressoes[maquina].tsimbolo == 1) {
					int indiceSimbolo = encontraSimbolo(tabela_simbolos, buff);
					if (indiceSimbolo == -1) {
						tabela_simbolos[nSimbolos].nome = (char *)malloc(sizeof(char) * (strlen(buff)+2));

						if (tabela_simbolos[nSimbolos].nome == NULL)
						{
							exit(1);
						}

						strncpy(tabela_simbolos[nSimbolos].nome, buff, cont);
						tabela_simbolos[nSimbolos].nome[cont] = '\0';
						tabela_simbolos[nSimbolos].cod = nSimbolos + 1;
						tabela_simbolos[nSimbolos].categoria = 1;

						// printf("anterior %s, %s\n", tabela_tokens[ntokens-1].str, buff);

						if ( strcmp(tabela_tokens[ntokens-1].str,"string") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 1;
						}
						else if ( strcmp(tabela_tokens[ntokens-1].str,"int") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 2;
						}
						else if ( strcmp(tabela_tokens[ntokens-1].str,"float") == 0  )
						{
							tabela_simbolos[nSimbolos].tipo = 3;
						}
						else
						{
							tabela_simbolos[nSimbolos].tipo = -1;
							panico(3,linha,coluna - cont,buff);
						}

						id = nSimbolos;
						indiceSimbolo = nSimbolos;
						nSimbolos++;

					} else {
						id = indiceSimbolo;
					}
				}

				tabela_tokens[ntokens].str = (char*) malloc(sizeof(char) * (strlen(buff) + 2));

				if (tabela_tokens[ntokens].str == NULL)
				{
					exit(1);
				}
				strncpy(tabela_tokens[ntokens].str, buff, cont);
				tabela_tokens[ntokens].str[cont] = '\0';
				tabela_tokens[ntokens].tipo = expressoes[maquina].tipo;
				tabela_tokens[ntokens].id = id;
				tabela_tokens[ntokens].cod = ntokens + 1;
				tabela_tokens[ntokens].linha = linha;
				// tabela_tokens[ntokens].coluna
				
				ntokens++;
			}
			
			c = buff[cont];
			
			for (it = 0; it <= MAX; it++)
			{
				buff[it] = '\0';
			}

			cont = 0;

			prioridadeant = MAX;
			maquina = -1;
			asp = 0;
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

	printf("TABELA DE SIMBOLOS\n");
	for(i = 0; i < nSimbolos; i++) {
		printf("nome %s, cod: %d, tipo %d\n", tabela_simbolos[i].nome, tabela_simbolos[i].cod, tabela_simbolos[i].tipo);
		free(tabela_simbolos[i].nome);
	}

	printf("\n\n\nTABELA DE TOKENS\n");
	for(i = 0; i < ntokens; i++) {
		printf("str %s, cod: %d, tipo %d, id %d\n", tabela_tokens[i].str, tabela_tokens[i].cod, tabela_tokens[i].tipo, tabela_tokens[i].id);
		free(tabela_tokens[i].str);
	}

	fclose(arquivo);
	free(buff);
	free(buffer);

	for (i = 0; i < N; i++)
	{
		free(expressoes[i].l1.s);
	}
	
	free(expressoes);

	return 0;
}
