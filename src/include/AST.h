#ifndef LOL_AST_H
#define LOL_AST_H

typedef struct AST_STRUCT {
  enum {
    AST_NOOP,
    AST_COMPOUND,
    AST_STATEMENT,
  } type;
} AST_t;

AST_t* init_ast(int type);

#endif
