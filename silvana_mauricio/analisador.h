#include "thompson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 35 //armazena o número de expressões
#define BUFFER_SIZE 8
#define MAX 8000

typedef struct _exp
{
	char *expressao;
	int tipo;
	int prioridade;
	int tsimbolo; 
	int id;
	State *maquina;
	List l1;
}Expressao;

typedef struct _bff
{
	char buffer1[BUFFER_SIZE+1];
	char buffer2[BUFFER_SIZE+1];
	int atual;
	int posBuffer;
	int lidos;
	int fimArquivo;
	int terminou;
	FILE *arquivo;
} Buffer;


typedef struct _tk
{
	char *str;
	int tipo;
	int id; // referencia tabela de simbolo
	int cod;
	int linha;
	int coluna;
}Token;

typedef struct _ts
{
	int cod;
	char *nome;
	int tipo;//string(1),int(2),float(3)
	int categoria;//tipo 1 é variável
}Simbolo;

FILE *abreArquivoFonte(char *filename);

Buffer *criaBuffer(FILE *arquivo);

Expressao *criaExpressoes();

/**
 * enche buffer secundário
 */
void encheBuffer(Buffer *buffer);

/**
 * Retorna próximo caractere válido do buffer ou EOF
 */
char proximoCaractere(Buffer *buffer);

/**
 * Verifica se um simbolo já esta na tabela de simbolos
 */
int encontraSimbolo(Simbolo *tabela, char *nome);

/**
 * Verifica se um token já esta na tabela de tokens
 */
int encontraToken(Token *tabela, char *token);

/**
 * Cria arquivo e joga dados no arquivo
 */
void cria_arquivo_tabela_simbolos(Simbolo *tabela_simbolos, int nSimbolos);

/**
 * Cria arquivo e joga dados no arquivo 
 */
void cria_arquivo_tabela_tokens(Token *tabela_tokens, int ntokens);

/**
 * Abre arquivo
 * Inicializa estrutura de buffer
 * Gera máquinas de estado
 * Intercala buffers
 * Verifica lexema válido
 * Se não for volta para o estado anterior onde era válido
 * Insere na tabela de tokens e simbolos
 * Verifica erros, caso ocorra entra em modo panico
 */
int executa(char *nome);