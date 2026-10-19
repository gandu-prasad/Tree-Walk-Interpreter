#include "token.h"

// Caller must free() the returned string.
char* tokenToString(const Token* token) {
    const char* typeStr = tokenTypeToString(token->type);
    const char* lexeme  = token->lexeme  ? token->lexeme  : "";
    const char* literal = token->literal ? token->literal : "null";

    // +2 for the two spaces, +1 for '\0'
    size_t len = strlen(typeStr) + strlen(lexeme) + strlen(literal) + 3;

    char* str = malloc(len);
    if (str == NULL) return NULL;

    snprintf(str, len, "%s %s %s", typeStr, lexeme, literal);
    return str;
}

