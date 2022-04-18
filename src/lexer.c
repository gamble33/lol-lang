#include "include/lexer.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

lexer_t* init_lexer(char* src) {
    lexer_t* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->index = 0;
    lexer->c = src[lexer->index];
    lexer->src_size = strlen(src);
    return lexer;
}

// ADVANCING LEXER

void lexer_skip_whitespace(lexer_t* lexer) {

  #define CHAR_TAB '\t'
  #define CHAR_NEWLINE '\n'
  #define CHAR_CARRIAGE_RETURN '\r'
  #define CHAR_WHITESPACE ' '

  while(
         lexer->c == CHAR_WHITESPACE 
      || lexer->c == CHAR_NEWLINE 
      || lexer->c == CHAR_CARRIAGE_RETURN 
      || lexer->c == CHAR_TAB) {
    lexer_advance(lexer);
  }
}

void lexer_advance(lexer_t* lexer) {
  if (lexer->index < lexer->src_size && lexer->c != '\0') {
    lexer->index += 1;
    lexer->c = lexer->src[lexer->index];
  }
}

token_t* lexer_advance_past_token(lexer_t* lexer, token_t* token) {
  lexer_advance(lexer);
  return token;
}

// LEXER PARSING

token_t* lexer_next(lexer_t* lexer){ 
  while(lexer-> c != '\0') {

    lexer_skip_whitespace(lexer);

    if(isalpha(lexer->c)) {
      return lexer_parse_id(lexer);
    }

    if(isdigit(lexer->c)) {
      return lexer_parse_number(lexer);

    }

    switch(lexer->c) {
      case  '.': return lexer_advance_past_token(lexer, init_token(".", TOKEN_PERIOD));
      case  '?': return lexer_advance_past_token(lexer, init_token("?", TOKEN_QUESTION_MARK));
      case '\0': break;
      default: {
        // TODO: HANDLE UNKOWN SYMBOL CASE
        printf("Unexpected Token: %c\n", lexer->c);
        exit(1);
        break;
      }
    }
  }
  return init_token(0, TOKEN_EOF);
}

token_t* lexer_parse_id(lexer_t* lexer) {
  char* value = calloc(1, sizeof(char));
  while(isalpha(lexer->c)) {
    value = realloc(value, sizeof(char) * (strlen(value) + 2));
    value = strcat(value, (char[]){lexer->c, 0});
    lexer_advance(lexer);
  }
  return init_token(value, TOKEN_ID) ;
}

token_t* lexer_parse_number(lexer_t* lexer) {
  char* value = calloc(1, sizeof(char));
  while(isdigit(lexer->c)) {
    value = realloc(value, sizeof(char) * (strlen(value) + 2));
    value = strcat(value, (char[]){lexer->c, 0});
    lexer_advance(lexer);
  }
  return init_token(value, TOKEN_INT_LITERAL);
}
