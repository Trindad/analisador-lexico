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

	if(match(startdstate(expressoes[2].maquina, &expressoes[2].l1), "mauriciocinelli+2@gmail.com", &(expressoes[2].l1))) {
		printf("%s\n", "mauriciocinelli+2@gmail.com");
	}

	if(match(startdstate(expressoes[31].maquina, &expressoes[31].l1), "<<", &(expressoes[31].l1))) {
		printf("%s\n", "<<");
	}

	if(match(startdstate(expressoes[2].maquina, &expressoes[2].l1), "mauriciocinelli+2@gmail.com", &(expressoes[2].l1))) {
		printf("%s\n", "mauriciocinelli+2@gmail.com");
	}
	
	return 0;
}
