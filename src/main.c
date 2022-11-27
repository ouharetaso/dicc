#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "token.h"

extern Token *token;

int main(int argc, char** argv){
	if(argc != 2){
		fprintf(stderr, "invalid argument number\n");
		return 1;
	}

	token = tokenize(argv[1]);

	printf(".global _start\n");
	printf(".align 2\n");
	printf("_start:\n");
	printf("	mov		x0, #%d\n", expect_number());

	while(is_eof()){
		if(consume('+')){
			printf("	add		x0, x0, #%d\n", expect_number());
			continue;
		}

		expect('-');
		printf("	sub		x0, x0, #%d\n", expect_number());
	}

	printf("	ret\n");
	return 0;
}
