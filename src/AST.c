#include "include/AST.h"
#include <stdlib.h>
 
AST_t* init_ast(int type) {
  AST_t* ast = calloc(1, sizeof(struct AST_STRUCT));
  ast->type = type;
  return ast;
}
