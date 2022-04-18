#ifndef TAC_TOKEN_H
#define TAC_TOKEN_H

typedef struct TOKEN_STRUCT {
    char* value;
    enum {

        // Identifier
        TOKEN_ID,

        // Literals
        TOKEN_INT_LITERAL,

        // Symbols
        TOKEN_QUESTION_MARK,
        TOKEN_PERIOD,
        TOKEN_KEYWORD,

        TOKEN_EOF,
        
    } type;
} token_t;

token_t* init_token(char* value, int type);
char* token_type_to_str(token_t*);

#endif
