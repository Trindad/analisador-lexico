#include "analisador.h"

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Arquivo de entrada não especificado.\n");
		printf("Padrão para executar:\n");
		printf("\t ./main <caminho_do_arquivo>.jusm\n\n");
		exit(1);
	}

	int tam = strlen(argv[1]);
	int i = tam;

	char extensao[6];
	
	if (tam >= 6)
	{
		int j = 0,limite = tam-5;

		for (i = limite; i < tam ; i++)
		{
			extensao[j] = argv[1][i];
			j++;
		}

		extensao[j] = '\0';
	}

	if ( strcmp(extensao,".jusm") )
	{
		fprintf(stderr, "extensão do arquivo '%s' esta errada \n",argv[1] );

		exit(1);
	}

	executa(argv[1]);

	return 0;
}
