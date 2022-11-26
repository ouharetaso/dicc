#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char** argv){
	if(argc != 2){
		fprintf(stderr, "invalid argument number\n");
		return 1;
	}

	printf(".global _start\n");
	printf(".align 2\n");
	printf("_start:\n");
	printf("	mov		x0, #%d\n", atoi(argv[1]));
	printf("	ret\n");
	return 0;
}
