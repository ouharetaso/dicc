#ifndef _TOKEN_H
#define _TOKEN_H

#include <stdbool.h>


typedef enum {
  TK_RESERVED, // 記号
  TK_NUM,      // 整数トークン
  TK_EOF,      // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

struct Token{
	TokenKind kind;
	Token *next;
	int val;
	char *str;
};

extern Token *token;

bool consume(char op);
void expect(char op);
int expect_number(void);
bool is_eof(void);
Token* new_token(TokenKind kind, Token *cur, char* str);
Token* tokenize(char* p);
void error(char *fmt, ...);



#endif