#include "include/AST.h"
#include <stdlib.h>
#include <stdio.h>
 
AST_t* init_ast(int type) {
  AST_t* ast = calloc(1, sizeof(struct AST_STRUCT));
  ast->type = type;

  if(type == AST_COMPOUND) {
    ast->children = init_list(sizeof(struct AST_STRUCT*));
  }

  return ast;
}

char* ast_type_to_str(AST_type_t type) {
  switch(type) { 
    case AST_NOOP: return "AST_NOOP";
    case AST_COMPOUND: return "AST_COMPOUND";
    case AST_STATEMENT: return "AST_STATEMENT";
    case AST_VARIABLE: return "AST_VARIABLE";
    case AST_ASSIGNMENT: return "AST_ASSIGNMENT";
    default: return "UNKOWN AST TYPE";
  }
}

void ast_print_recursive(AST_t* root, unsigned int depth) {
  if(depth == 0) {
    printf("%s\n", ast_type_to_str(root->type));
  }
  // char* arrow = calloc(depth)
}
