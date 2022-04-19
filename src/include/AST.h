#ifndef LOL_AST_H
#define LOL_AST_H

#include "list.h"

typedef enum AST_TYPE_ENUM {
    AST_NOOP,
    AST_COMPOUND,
    AST_STATEMENT,
    AST_VARIABLE,
    AST_ASSIGNMENT,
    AST_INT,
 } AST_type_t;

typedef struct AST_STRUCT {
  AST_type_t type;
  list_t* children;
  struct AST_STRUCT* value;
  char* name;
} AST_t;

AST_t* init_ast(int type);
char* ast_type_to_str(AST_type_t);
void ast_print_recursive(AST_t* root, unsigned int depth);

#endif
