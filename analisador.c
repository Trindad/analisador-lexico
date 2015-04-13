#include "analisador.h"

Expressao *criaExpressoes()
{
	Expressao *exp = (Expressao*) malloc ( sizeof(Expressao) * N);

	if (exp == NULL)
	{
		printf("Erro na alocação de memória.\n");
		exit(1);
	}

	/**
	 *----------------------TIPO--------------------------
	 * 
	 * tipo 1 = identificador
	 * tipo 2 = operador
	 * tipo 3 = constante (string,ponto flutuante,inteiro)
	 * tipo 4 = palavra reservada
	 *
	 * ---------------------PRIORIDADE---------------------
	 * Alta prioridade = 1
	 * Média prioridade = 2
	 * Baixa prioridade = 3
	 */


	exp[0].expressao = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|x|w|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|_)(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|x|w|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|0|1|2|3|4|5|6|7|8|9|_)*";//identificador
	exp[0].tsimbolo = 1;
	exp[0].tipo = 1;
	exp[0].prioridade = 2;
	exp[0].id = 1;

	exp[1].expressao = "(0|1|2|3|4|5|6|7|8|9)+"; //números inteiros
	exp[1].tsimbolo = 0;
	exp[1].tipo = 3;
	exp[1].prioridade = 3;
	exp[1].id = 2;


	exp[2].expressao = "\"(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|x|w|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|0|1|2|3|4|5|6|7|8|9|@|#|$|_|{|}|[|]|%|\\+|\\?|\\*|<|>|:|;|/|\\|-|'|\\.|\\s)*\"";//string 
	exp[2].tsimbolo = 0;
	exp[2].tipo = 3;
	exp[2].prioridade = 3;
	exp[2].id = 3;


	exp[3].expressao = ">";//operador maior
	exp[3].tsimbolo = 0;
	exp[3].tipo = 2;
	exp[3].prioridade = 1;
	exp[3].id = 4;


	exp[4].expressao = "<";//operador menor 
	exp[4].tsimbolo = 0;
	exp[4].tipo = 2;
	exp[4].prioridade = 1;
	exp[4].id = 5;


	exp[5].expressao = ">=";//operador maior igual
	exp[5].tsimbolo = 0;
	exp[5].tipo = 2;
	exp[5].prioridade = 1;
	exp[5].id = 6;


	exp[6].expressao = "<=";//operador de soma
	exp[6].tsimbolo = 0;
	exp[6].tipo = 2;
	exp[6].prioridade = 1;
	exp[6].id = 7;

	exp[7].expressao = "\\+";//operador de soma
	exp[7].tsimbolo = 0;
	exp[7].tipo = 2;
	exp[7].prioridade = 1;
	exp[7].id = 8;


	exp[8].expressao = "-";//operador de subtração
	exp[8].tsimbolo = 0;
	exp[8].tipo = 2;
	exp[8].prioridade = 1;
	exp[8].id = 9;

	exp[9].expressao = "\\*";//operador de multiplicação
	exp[9].tsimbolo = 0;
	exp[9].tipo = 2;
	exp[9].prioridade = 1;
	exp[9].id = 10;


	exp[10].expressao = "/";//operador de divisão
	exp[10].tsimbolo = 0;
	exp[10].tipo = 2;
	exp[10].prioridade = 1;
	exp[10].id = 11;

	exp[11].expressao = "%";//operador de modulo
	exp[11].tsimbolo = 0;
	exp[11].tipo = 2;
	exp[11].prioridade = 1;
	exp[11].id = 12;

	exp[12].expressao = "=";//operador =
	exp[12].tsimbolo = 0;
	exp[12].tipo = 2;
	exp[12].prioridade = 1;
	exp[12].id = 13;

	exp[13].expressao = "!";//operador de negação
	exp[13].tsimbolo = 0;
	exp[13].tipo = 2;
	exp[13].prioridade = 1;
	exp[13].id = 14;

	exp[14].expressao = "==";//operador de igualdade
	exp[14].tsimbolo = 0;
	exp[14].tipo = 2;
	exp[14].prioridade = 1;
	exp[14].id = 15;

	exp[15].expressao = "to";//iterador de laço
	exp[15].tsimbolo = 0;
	exp[15].tipo = 4;
	exp[15].prioridade = 1;
	exp[15].id = 16;

	exp[16].expressao = "or";//operador de igualdade
	exp[16].tsimbolo = 0;
	exp[16].tipo = 2;
	exp[16].prioridade = 1;
	exp[16].id = 17;

	exp[17].expressao = "and";//operador and
	exp[17].tsimbolo = 0;
	exp[17].tipo = 2;
	exp[17].prioridade = 1;
	exp[17].id = 18;

	exp[18].expressao = "!=";//operador de diferença
	exp[18].tsimbolo = 0;
	exp[18].tipo = 2;
	exp[18].prioridade = 1;
	exp[18].id = 19;

	exp[19].expressao = "::";//demarcador de comentario
	exp[19].tsimbolo = 0;
	exp[19].tipo = 4;
	exp[19].prioridade = 1;
	exp[19].id = 20;


	exp[20].expressao = "begin";//inicio de condição
	exp[20].tsimbolo = 0;
	exp[20].tipo = 4;
	exp[20].prioridade = 1;
	exp[20].id = 21;

	exp[21].expressao = "end";//fim de condição
	exp[21].tsimbolo = 0;
	exp[21].tipo = 4;
	exp[21].prioridade = 1;
	exp[21].id = 22;

	exp[22].expressao = "main";//main
	exp[22].tsimbolo = 0;
	exp[22].tipo = 4;
	exp[22].prioridade = 1;
	exp[22].id = 23;


	exp[23].expressao = "int";//inteiro
	exp[23].tsimbolo = 0;
	exp[23].tipo = 4;
	exp[23].prioridade = 1;
	exp[23].id = 24;

	exp[24].expressao = "float";//ponto flutuante
	exp[24].tsimbolo = 0;
	exp[24].tipo = 4;
	exp[24].prioridade = 1;
	exp[24].id = 25;

	exp[25].expressao = "string";//string
	exp[25].tsimbolo = 0;
	exp[25].tipo = 4;
	exp[25].prioridade = 1;
	exp[25].id = 26;

	exp[26].expressao = "print";//imprime
	exp[26].tsimbolo = 0;
	exp[26].tipo = 4;
	exp[26].prioridade = 1;
	exp[26].id = 27;


	exp[27].expressao = "if";//se 
	exp[27].tsimbolo = 0;
	exp[27].tipo = 4;
	exp[27].prioridade = 1;
	exp[27].id = 28;

	exp[28].expressao = "while";//laço
	exp[28].tsimbolo = 0;
	exp[28].tipo = 4;
	exp[28].prioridade = 1;
	exp[28].id = 29;

	exp[29].expressao = "scan";//scanner
	exp[29].tsimbolo = 0;
	exp[29].tipo = 4;
	exp[29].prioridade = 1;
	exp[29].id = 30;

	exp[30].expressao = "for";//laço
	exp[30].tsimbolo = 0;
	exp[30].tipo = 4;
	exp[30].prioridade = 1;
	exp[30].id = 31;

	exp[31].expressao = "in";
	exp[31].tsimbolo = 0;
	exp[31].tipo = 4;
	exp[31].prioridade = 1;
	exp[31].id = 32;

	exp[32].expressao = "(0|1|2|3|4|5|6|7|8|9)+(,(0|1|2|3|4|5|6|7|8|9)*)";
	exp[32].tsimbolo = 0;
	exp[32].tipo = 3;
	exp[32].prioridade = 3;
	exp[32].id = 33;

	exp[33].expressao = "\\)";
	exp[33].tsimbolo = 0;
	exp[33].tipo = 2;
	exp[33].prioridade = 2;
	exp[33].id = 34;

	exp[34].expressao = "\\(";
	exp[34].tsimbolo = 0;
	exp[34].tipo = 2;
	exp[34].prioridade = 2;
	exp[34].id = 35;

	return exp;
}

FILE *abreArquivoFonte(char *filename)
{
	FILE *arquivo = fopen(filename, "r+");

	if (!arquivo) 
	{
		printf("Não foi possível abrir arquivo fonte\n");
		exit(EXIT_FAILURE);
	}

	return arquivo;
}

Buffer *criaBuffer(FILE *arquivo)
{
	Buffer *buf = (Buffer *) malloc(sizeof(Buffer));

	if (!buf || !arquivo) {
		printf("Sem memória disponível\n");
		exit(EXIT_FAILURE);
	}

	buf->atual = 2;
	buf->arquivo = arquivo;
	buf->lidos = 0;
	buf->terminou = 0;
	buf->posBuffer = 0;

	encheBuffer(buf);
	buf->atual = 1;
	encheBuffer(buf);

	return buf;
}

void encheBuffer(Buffer *buffer)
{
	if ( feof(buffer->arquivo) )
	{
		if (buffer->atual == 1)
		{
			buffer->buffer2[0] = '\0';
		} else
		{
			buffer->buffer1[0] = '\0';
		}		
		buffer->fimArquivo = 1;
		return;
	}

	char c = '\0',ant = '\0';
	int n = 0;

	char buf[BUFFER_SIZE+1];

	while (n < BUFFER_SIZE) {
		
		fread(&c, sizeof(char),1, buffer->arquivo);
		
		if (c == EOF)
		{
			break;
		}
		// printf("%c",c);

		if ( ( ant == ':' && c == ':' ) || ( ant == ':' && c != '\n' ))
		{
			continue;
		}
		if (feof(buffer->arquivo)) 
		{
			buffer->fimArquivo = 1;
			break;
		}

		if (c != ':')
		{
			buf[n] = c;
			n++;
		}

		ant = c;
	}

	buf[n] = '\0';
	
	if (buffer->atual == 1)
	{
		int j = 0;
		for (j = 0; j < BUFFER_SIZE; j++) {
			buffer->buffer2[j] = '\0';
		}

		strcpy(buffer->buffer2, buf);
	}
	else
	{
		int j = 0;
		for (j = 0; j < BUFFER_SIZE; j++) {
			buffer->buffer1[j] = '\0';
		}
		strcpy(buffer->buffer1, buf);
	}
}

/**
 * Retorna próximo caractere válido do buffer ou EOF
 */
char proximoCaractere(Buffer *buffer)
{
	char c = '\0';

	if (buffer->atual == 1) {
		c = buffer->buffer1[buffer->posBuffer];
	} else {
		c = buffer->buffer2[buffer->posBuffer];
	}


	buffer->posBuffer++;
	// printf("%c pos %d",c,buffer->posBuffer);
	// 
	if (buffer->posBuffer >= BUFFER_SIZE) {

		buffer->atual = buffer->atual == 1 ? 2 : 1;

		if ((buffer->atual == 1 && buffer->buffer1[0] == '\0') ||
			(buffer->atual == 2 && buffer->buffer2[0] == '\0'))
		{
			buffer->terminou = 1;
			return EOF;
		}

		buffer->posBuffer = 0;
		encheBuffer(buffer);
	}
	
	return c;
}

int encontraSimbolo(Simbolo *tabela, char *nome)
{
	int indice = -1, i;
	for (i = 0; i < MAX; i++) {
		if (tabela[i].nome == NULL) {
			continue;
		}

		if (strcmp(tabela[i].nome, nome) == 0) {
			indice = i;
			break;
		}
	}

	return indice;
}

int encontraToken(Token *tabela, char *token)
{
	int indice = -1, i;
	for (i = 0; i < MAX; i++) {
		if (!tabela[i].str) {
			continue;
		}

		if (strcmp(tabela[i].str, token) == 0) {
			indice = i;
			break;
		}
	}

	return indice;
}

//entra com codigo de erro léxico, a linha onde o erro ocorreu e o erro 
//erro = 1 para string ok
//erro = 2 simbolos não pertencentes ao conjunto ok 
//erro = 3 variavel utilizada mas não declarada
void panico(int erro,int linha, int coluna, char *str)
{
	switch(erro)
	{
		case 1:
			fprintf(stderr, "String \"%s\" não terminada na linha %d, coluna %d\n", str, linha, coluna);
			break;
		case 2:
			fprintf(stderr, "Token \"%s\" não esperado na linha %d, coluna %d\n", str, linha, coluna);
			break;
		case 3:
			fprintf(stderr, "Variável \"%s\" não declarada e usada pela primeira vez na linha %d, coluna %d\n", str, linha, coluna);	
			break;
		default:
			break;
	}

	return;
}

void cria_arquivo_tabela_simbolos(Simbolo *tabela_simbolos, int nSimbolos)
{
	FILE *file = fopen("tabela_simbolos.txt", "w+");
	fprintf(file, "TABELA DE SIMBOLOS\n");
	fprintf(file, "==================\n\n");

	int i;
	for(i = 0; i < nSimbolos; i++) {
		const char *categoria = tabela_simbolos[i].categoria == 1 ? "variável" : "indefinido";
		const char *tipo = tabela_simbolos[i].tipo == 1 ? "string" : (tabela_simbolos[i].tipo == 2 ? "int" : (tabela_simbolos[i].tipo == 3 ? "float" : "indefinido"));
		fprintf(file, "simbolo: %s, codigo: %d, categoria: %s, tipo: %s\n", tabela_simbolos[i].nome, tabela_simbolos[i].cod, categoria, tipo);
	}
}

void cria_arquivo_tabela_tokens(Token *tabela_tokens, int ntokens)
{
	FILE *file = fopen("tabela_tokens.txt", "w+");
	fprintf(file, "TABELA DE TOKENS\n");
	fprintf(file, "==================\n\n");

	int i;
	for(i = 0; i < ntokens; i++) {
		const char *tipo = tabela_tokens[i].tipo == 1 ? "identificador" : (tabela_tokens[i].tipo == 2 ? "operador" : (tabela_tokens[i].tipo == 3 ? "constante" : "palavra reservada"));
		fprintf(file, "token: %s, codigo: %d, ref. tabela simbolo: %d, tipo: %s, linha: %d, coluna: %d\n", tabela_tokens[i].str, tabela_tokens[i].cod, (tabela_tokens[i].id > -1 ? tabela_tokens[i].id+1 : -1) , tipo, tabela_tokens[i].linha, tabela_tokens[i].coluna);
	}
}

int executa(char *nome) 
{
	int i;
	char *post;
	State *start;
	int teveErros = 0;

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

	FILE *arquivo = abreArquivoFonte(nome);
	Buffer *buffer = criaBuffer(arquivo);

	for (i = 0; i < N; i++) {
		post = re2post(expressoes[i].expressao);

		if(post == NULL){
			fprintf(stderr, "regeita regex %s\n", expressoes[i].expressao);
			return 1;
		}

		start = post2nfa(post);

		if(start == NULL){
			fprintf(stderr, "erro  em post2nfa %s\n", post);
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
			teveErros = 1;
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
					teveErros = 1;
				} else {
					panico(2, linha, coluna - cont - 1,buff);
					teveErros = 1;
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
							teveErros = 1;
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

				if (c == '\n') {
					tabela_tokens[ntokens].linha = linha - 1;
					tabela_tokens[ntokens].coluna = colunaAnterior - cont + 1;
				} else {
					tabela_tokens[ntokens].linha = linha;
					tabela_tokens[ntokens].coluna = coluna - cont;
				}
				
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
							teveErros = 1;
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
				tabela_tokens[ntokens].coluna = coluna - cont;
				
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

	cria_arquivo_tabela_simbolos(tabela_simbolos, nSimbolos);

	for(i = 0; i < nSimbolos; i++) {
		free(tabela_simbolos[i].nome);
	}

	cria_arquivo_tabela_tokens(tabela_tokens, ntokens);

	for(i = 0; i < ntokens; i++) {
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

	if (teveErros) {
		printf("\nAnálise léxica finalizada, porém os erros acima ocorreram!\n");
	} else {
		printf("\nAnálise léxica finalizada com sucesso!\n");
	}
	printf("Os arquivos \"tabela_tokens.txt\" e \"tabela_simbolos.txt\" foram criados na pasta de trabalho atual.\n");


}