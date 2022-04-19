#ifndef LOL_TOKEN_H
#define LOL_TOKEN_H

typedef enum TOKEN_TYPE_ENUM {

        // Identifier
        TOKEN_ID,

        // Literals
        TOKEN_INT_LITERAL,

        // Symbols
        TOKEN_QUESTION_MARK,
        TOKEN_PERIOD,

        // Keywords
        TOKEN_KEYWORD_HAS,

        TOKEN_EOF,

} token_type_t;

typedef struct TOKEN_STRUCT {
    char* value;
    token_type_t type;
} token_t;

token_t* init_token(char* value, token_type_t type);
char* token_type_to_str(token_type_t);

#endif
