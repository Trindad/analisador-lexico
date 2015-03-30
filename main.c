#include "thompson.c"
#include "analisador.h"

int main(int argc, char **argv)
{
	int i;
	char *post;
	State *start;

	Expressao *expressoes = criaExpressoes();

	FILE *arquivo = abreArquivoFonte("example.jusm");
	Buffer *buffer = criaBuffer(arquivo);

	int count = 0;
	char c;
	char temp[2000];

	while (c != EOF) {
		c = proximoCaractere(buffer);
		
		if (c == EOF) {
			break;
		}

		temp[count++] = c;
		//printf("%c", c);
	}

	temp[count] = '\0';

	printf("%s\n", temp);

	// if(argc < 3){
	// 	fprintf(stderr, "usage: nfa regexp string...\n");
	// 	return 1;
	// }
	
	// post = re2post(argv[1]);
	// if(post == NULL){
	// 	fprintf(stderr, "bad regexp %s\n", argv[1]);
	// 	return 1;
	// }

	// start = post2nfa(post);
	// if(start == NULL){
	// 	fprintf(stderr, "error in post2nfa %s\n", post);
	// 	return 1;
	// }
	
	// l1.s = malloc(nstate*sizeof l1.s[0]);
	// l2.s = malloc(nstate*sizeof l2.s[0]);
	// for(i=2; i<argc; i++)
	// 	if(match(startdstate(start), argv[i]))
	// 		printf("%s\n", argv[i]);
	return 0;
}
