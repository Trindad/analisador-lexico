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
	}
	
	
	
	// l1.s = malloc(nstate*sizeof l1.s[0]);
	// l2.s = malloc(nstate*sizeof l2.s[0]);
	// for(i=2; i<argc; i++)
	// 	if(match(startdstate(start), argv[i]))
	// 		printf("%s\n", argv[i]);
	return 0;
}
