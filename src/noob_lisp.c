#include <stdio.h>
#include <stdlib.h>

//start of c preprocessor
//in case of windows program, execute so that code does not need to be changed
#ifdef _WIN32
#include <string.h>

static char* buffer[2048]

char* readline*(char* prompt){
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	stcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

void add_history(char* unused){}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif
//end of c preprocessor

int main(int argc, char** argv){
	puts("Welcome to noobLisp Ver 0");
	puts("Please enter Ctrl-c to exit program");

	while(1){
					char* input = readline("Lispy > ");
					add_history(input);

					printf("No you %s\n", input);
					free(input);
	}
	return 0;
}

