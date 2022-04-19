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
    case AST_INT: return "AST_INT";
    case AST_SUMMARIZE: return "AST_SUMMARIZE";                    
    default: return "UNKOWN AST TYPE";
  }
}

void ast_print_recursive(AST_t* root, unsigned int depth) {

  if(depth > 0) {
    unsigned int arrow_length = depth * 2;
    char* arrow = calloc(arrow_length + 1, sizeof(char));
    arrow[arrow_length] = '\0';
    for(unsigned int i=0; i<arrow_length-1; i++) {
      arrow[i] = '-';
    }
    printf("%s>", arrow);
    free(arrow);
  }
  printf("%s %s", ast_type_to_str(root->type), root->name);
  if(root->value != NULL) {
    printf(" (%s)", root->value->name);
  }
  printf("\n");
  
  if(root->children != NULL) {
    for(size_t i=0; i<root->children->size; i++) {
      ast_print_recursive((AST_t*)list_get(root->children, i), depth + 1);
    }
  }
}
