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
	exp[32].tipo = 4;
	exp[32].prioridade = 1;
	exp[32].id = 33;

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
		strcpy(buffer->buffer2, buf);
	}
	else
	{
		strcpy(buffer->buffer1, buf);
	}
}

/**
 * Retorna próximo caractere válido do buffer ou EOF
 */
char proximoCaractere(Buffer *buffer)
{
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
	
	char c = '\0';

	if (buffer->atual == 1) {
		c = buffer->buffer1[buffer->posBuffer];
	} else {
		c = buffer->buffer2[buffer->posBuffer];
	}


	buffer->posBuffer++;
	// printf("%c pos %d",c,buffer->posBuffer);
	
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
void panico(int erro,int linha,char *str)
{
	switch(erro)
	{
		case 1:
			fprintf(stderr, "String \"%s\" não terminada na linha %d\n", str, linha);
			break;
		case 2:
			fprintf(stderr, "Token \"%s\" não esperado na linha %d\n", str, linha);
			break;
		case 3:
			fprintf(stderr, "Variável \"%s\" não declarada e usada pela primeira vez na linha %d\n", str, linha);	
			break;
		default:
			break;
	}

	return;
}