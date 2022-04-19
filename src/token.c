#include "include/token.h"
#include <stdlib.h>

token_t* init_token(char* value, token_type_t type) {
    token_t* token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;
    return token;
}

char* token_type_to_str(token_t* token) {
  switch(token->type) {
        case                TOKEN_ID: return "TOKEN_ID";
        case       TOKEN_INT_LITERAL: return "TOKEN_INT_LITERAL";
        case     TOKEN_QUESTION_MARK: return "TOKEN_QUESTION_MARK";
        case            TOKEN_PERIOD: return "TOKEN_PERIOD";
        case       TOKEN_KEYWORD_HAS: return "TOKEN_KEYWORD_HAS";
        case           TOKEN_EOF: return "TOKEN_EOF";
        default:                  return "UNKOWN_TOKEN";
  }
  
}
