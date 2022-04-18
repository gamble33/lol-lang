#ifndef LOL_LEXER_H
#define LOL_LEXER_H

#include "token.h"

#include <stdio.h>

typedef struct LEXER_STRUCT {
    char* src;
    size_t src_size;
    char c;
    unsigned int index;
} lexer_t;

lexer_t* init_lexer(char* src);

void lexer_advance(lexer_t*);
void lexer_skip_whitespace(lexer_t*);
token_t* lexer_advance_past_token(lexer_t*, token_t*);
char lexer_peek(lexer_t*, unsigned int offset);

token_t* lexer_next(lexer_t*);
token_t* lexer_parse_id(lexer_t*);
token_t* lexer_parse_number(lexer_t*);

#endif
