#include "lexer.h"

T_token create_end_token()
{
    // using malloc to allocate a new token structure
    T_token token = malloc(sizeof(*token)); 
    token->kind = END;
    return token;
}

T_token create_number_token(char c)
{
    T_token token = malloc(sizeof(*token));
    token->kind = NUMBER;

    // atoi can do the same
    token->number = c - '0';
    return token;
}

T_token create_operator_token(char c)
{
    T_token token = malloc(sizeof(*token));
    token->kind = OPERATOR;
    token->character = c;
    return token;
}

T_token create_semicolon_token()
{
    T_token token = malloc(sizeof(*token));
    token->kind = SEMICOLON;
    return token;
}

T_token lex()
{
/*
    * EOF? - if reach the end of the file then return an end token

    * NUMBER? return a number token

    * semicolon? return a semicolon token
    
    * space? continue with the next character 

    * operator? return a operator token

    * something else?
*/

    char c = fgetc(stdin);

    // EOF
    if(EOF == c)
    {
        return create_end_token();
    }

    // NUMBER
    else if (isdigit(c))
    {
        return create_number_token(c);
    }

    // semicolon
    else if (';' == c)
    {
        return create_semicolon_token();
    }

    // space character, newline, space, tab
    else if (isspace(c))
    {
        return lex();
    }

    else
    {
        switch (c)
        {
            case '+':
                // fall through
            case '-':
                // fall through
            case '*':
                // fall through
            case '/':
                return create_operator_token(c); // since return no need break
            default:
                // switch is in the else (outer) path and default branch handle every other character in the input.
                lexer_error();
                break;
        }
    }
}

void lexer_error()
{
    fprintf(stderr, "lexer error.\n");
    exit(1);
}