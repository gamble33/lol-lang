#include "include/lol.h"
#include "include/lexer.h"
#include "include/token.h"
#include "include/parser.h"

void lol_compile(char* src) {
  lexer_t* lexer = init_lexer(src);
  parser_t* parser = init_parser(lexer);
  AST_t* ast_root = parser_parse(parser);
  ast_print_recursive(ast_root, 1);
  printf("%p, size: %lu\n", ast_root, ast_root->children->size);
}

