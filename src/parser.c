#include "include/parser.h"
#include <stdlib.h>

parser_t* init_parser(lexer_t* lexer) {
  parser_t* parser = calloc(1, sizeof(struct PARSER_STRUCT));
  parser->lexer = lexer;
  parser->token = lexer_next(lexer);
  return parser;
}

token_t* parser_eat(parser_t* parser, int type) {
  if (parser->token->type != type) {
    printf("Unexpected token: %s\n", parser->token->value);
    exit(1);
  } 
  parser->token = lexer_next(parser->lexer);
  return parser->token;
}

AST_t* parser_parse(parser_t* parser) {
  return init_ast(AST_COMPOUND);
}

AST_t* parser_parse_compound(parser_t* parser) {
  AST_t* compound = init_ast(AST_COMPOUND);

  while(parser->token->type != TOKEN_EOF) {
    AST_t* child = parser_parse(parser);
    list_push(compound->children, child);
  }
  return init_ast(AST_NOOP);
}
