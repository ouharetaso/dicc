#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char** argv){
	if(argc != 2){
		fprintf(stderr, "invalid argument number\n");
		return 1;
	}

	char *p = argv[1];

	printf(".global _start\n");
	printf(".align 2\n");
	printf("_start:\n");
	printf("	mov		x0, #%ld\n", strtol(p, &p, 10));

	while(*p){
		if(*p == '+'){
			p++;
			printf("	add		x0, x0, #%ld\n", strtol(p, &p, 10));
			continue;
		}
		if(*p == '-'){
			p++;
			printf("	sub		x0, x0, #%ld\n", strtol(p, &p, 10));
			continue;
		}
		fprintf(stderr, "unexpected character\n");
		return 1;		
	}

	printf("	ret\n");
	return 0;
}
