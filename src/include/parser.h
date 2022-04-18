#ifndef LOL_PARSER_H
#define LOL_PARSER_H

#include "lexer.h"
#include "AST.h"

typedef struct PARSER_STRUCT {
  lexer_t* lexer;
  token_t* token;
} parser_t;

parser_t* init_parser(lexer_t*);

token_t* parser_eat(parser_t*, int type);
AST_t* parser_parse(parser_t*);
AST_t* parser_parse_compound(parser_t*);

#endif
