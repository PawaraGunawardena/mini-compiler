#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>  // fgetc() and EOF
#include <ctype.h>  // isdigit() and isspace()
#include <stdlib.h> // exit()  exit with an error code

/*
    This T_Token type definition use to hide pointers behind the defined type and can use pointers with the defined T_token type in an easier way than use the struct S_token* pointer directly.
*/
typedef struct S_token* T_token;


/**
 * This is the type of structure that contains the token details
 *      Token type (NUMBER, OPERATOR, SEMICOLON, END)
 *      Data value (number or character)
 */
struct S_token 
{
    enum {NUMBER, OPERATOR, SEMICOLON, END} kind;

    union
    {
        int number;
        char character;
    };
};

/**
 * This lex function is what exposed from the lexer and it process the file reading at the time and returns a token
 *
 * @return
 *     The token is returned.
 */
T_token lex();

/**
 * This function is for error handling
 * Terminate if it find input does not match the lexical specification
 */
void lexer_error();

/**
 * Function to create end token.
 *
 * @return
 *     End token is returned.
 */
T_token create_end_token();

/**
 * Function to create number token.
 *
 * @param[in] c
 *     This is the character (ASCII) of the number.
 *
 * @return
 *     Number token is returned
*/
T_token create_number_token(char c);

/**
 * Function to create operator token.
 *
 * @param[in] c
 *     This is the character (ASCII) of the operator.
 *
 * @return
 *     Operator token is returned
*/
T_token create_operator_token(char c);

/**
 * Function to create semicolon token.
 *
 * @return
 *     Semicolon token is returned.
 */
T_token create_semicolon_token();

#endif