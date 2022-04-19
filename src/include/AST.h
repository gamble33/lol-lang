#ifndef LOL_AST_H
#define LOL_AST_H

#include "list.h"

typedef struct AST_STRUCT {
  enum {
    AST_NOOP,
    AST_COMPOUND,
    AST_STATEMENT,
    AST_VARIABLE,
    AST_ASSIGNMENT,
  } type;
  list_t* children;
  struct AST_STRUCT* value;
  char* name;
} AST_t;

AST_t* init_ast(int type);

#endif
