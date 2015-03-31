#include "thompson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32 //armazena o número de expressões
#define BUFFER_SIZE 8

typedef struct _exp
{
	char *expressao;
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

FILE *abreArquivoFonte(char *filename);
Buffer *criaBuffer(FILE *arquivo);
Expressao *criaExpressoes();

// enche buffer secundário
void encheBuffer(Buffer *buffer);

/**
 * Retorna próximo caractere válido do buffer ou EOF
 */
char proximoCaractere(Buffer *buffer);