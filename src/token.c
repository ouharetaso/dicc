#include "token.h"
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

Token *token;


bool consume(char op){
	if(token->kind != TK_RESERVED || token->str[0] != op){
		return false;
	}
	token = token->next;
	return true;
}


void expect(char op){
	if(token->kind != TK_RESERVED || token->str[0] != op){
		error("expected '%c'", op);
	}
	token = token->next;
}


int expect_number(void){
	if(token->kind != TK_NUM){
		error("expected number");
	}
	int val = token->val;
	token = token->next;
	return val;
}


bool is_eof(void){
	return token->kind == TK_EOF;
}


Token* new_token(TokenKind kind, Token *cur, char* str){
	Token *tok = calloc(1, sizeof(Token));
	tok->kind = kind;
	tok->str = str;
	cur->next = tok;
	return tok;
}


Token* tokenize(char* p){
	Token head;
	head.next = NULL;
	Token *cur = &head;

	while(*p){
		if(*p == ' ' || *p == '\n' || *p == '	' || *p == '\r'){
			p++;
			continue;
		}

		if(*p == '+' || *p =='-' ){
			cur = new_token(TK_RESERVED, cur, p++);
			continue;
		}

		if( '0' <= *p && *p <= '9' ){
			cur = new_token(TK_NUM, cur, p);
			cur->val = strtol(p, &p, 10);
			continue;
		}

		error("cannot tokenize");
	}

	new_token(TK_EOF, cur, p);
	return head.next;
}


void error(char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	exit(1);
}