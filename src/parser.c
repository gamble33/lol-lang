#include "include/parser.h"
#include <string.h>
#include <stdlib.h>

parser_t* init_parser(lexer_t* lexer) {
  parser_t* parser = calloc(1, sizeof(struct PARSER_STRUCT));
  parser->lexer = lexer;
  parser->token = lexer_next(lexer);
  return parser;
}

token_t* parser_eat(parser_t* parser, token_type_t type) {
  if (parser->token->type != type) {
    printf("Unexpected token: %s\n", parser->token->value);
    exit(1);
  } 
  parser->token = lexer_next(parser->lexer);
  return parser->token;
}

AST_t* parser_parse(parser_t* parser) {
  return parser_parse_compound(parser);
}

AST_t* parser_parse_compound(parser_t* parser) {
  AST_t* compound = init_ast(AST_COMPOUND);

  while(parser->token->type != TOKEN_EOF) {
    AST_t* child = parser_parse_expr(parser);
    printf("compound child --> %s\n", child->name);
    list_push(compound->children, child);
  }
  return init_ast(AST_NOOP);
}

AST_t* parser_parse_id(parser_t* parser) {
  char* value = calloc(strlen(parser->token->value) + 1, sizeof(char)); 
  strcpy(value, parser->token->value);
  parser_eat(parser, TOKEN_ID);

  if(parser->token->type == TOKEN_KEYWORD_HAS) {
    // Variable Assignment
    parser_eat(parser, TOKEN_KEYWORD_HAS);
    AST_t* ast = init_ast(AST_ASSIGNMENT);
    ast->name = value;
    printf("%s has ...\n", value);
    ast->value = parser_parse_expr(parser);
    return ast;
  } else {
    // Variable
    AST_t* ast = init_ast(AST_VARIABLE);
    ast->name = value;
  }

}

AST_t* parser_parse_expr(parser_t* parser) {
  switch(parser->token->type) {
    case TOKEN_ID: return parser_parse_id(parser);
    default: {
      printf("Unexpected Token: `%s`", parser->token->value);
      exit(1);
    }
  }
}
