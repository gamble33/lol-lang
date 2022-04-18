#include "include/lol.h"
#include "include/lexer.h"
#include "include/token.h"

void lol_compile(char* src) {
  lexer_t* lexer = init_lexer(src);
  token_t* token = 0;
  
  while((token = lexer_next(lexer))->type != TOKEN_EOF) {
    printf("[Token `%s`: %s]\n", token->value, token_type_to_str(token));
  }
}
