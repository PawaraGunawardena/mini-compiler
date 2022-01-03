#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "lexer.h"

/**
typedef creation for the three constructs in the language which need to create the Abstract Syntax Tree in Parser.
    * statement_list: contains a statement and next list
    * statement: contains an expression
    * expression: contains two operands and an operator (all tokens)
*/
typedef struct S_statement_list* T_statement_list;
typedef struct S_statement* T_statement;
typedef struct S_expression* T_expression;

/**
* statement list construct contains a statement followed by another statement list
    * statement_list: contains a statement and next list
*/
struct S_statement_list 
{
    T_statement statement;
    T_statement_list statement_list;
};

/**
* statement construct contains an expression
    * statement: contains an expression
*/
struct S_statement
{
    T_expression expression;
};

/**
* expression construct contains three tokens
    * expression: contains two operands and an operator (all tokens)
*/
struct S_expression
{
    T_token operand1_token;
    T_token operator_token;    
    T_token operand2_token;
};

/**
 * This function parse statement_list and return T_statement_list instance which is a node in the Abstract Syntax Tree (AST). 
 *
 * @return
 *     Statement list node of the Abstract Syntax Tree (AST).
 */
T_statement_list parse_statement_list();

/**
 * This function parse statement and return T_statement instance which is a node in the Abstract Syntax Tree (AST). 
 *
 * @return
 *     Statement node of the Abstract Syntax Tree (AST).
 */
T_statement parse_statement();

/**
 * This function parse expression and return T_expression instance which is a node in the Abstract Syntax Tree (AST). 
 *
 * @return
 *     Expression node of the Abstract Syntax Tree (AST).
 */
T_expression parse_expression();

/**
 * This function creates and returns statement_list AST node. 
 * It needs a statement and a statement_list as the input parameters to create a new statement_list AST node. 
 * It returns the newly created statement_list AST node.
 *
 * @param[in] statement
 *     This is a statement AST node.
 *
 * @param[in] statement_list
 *     This is a statement_list AST node.
 *
 * @return
 *     statement_list AST node.
 */
T_statement_list create_statement_list(T_statement statement, T_statement_list statement_list);

/**
 * This function creates and returns statement AST node.
 * It needs an expression as the input parameter to create a new statement AST node.
 *
 * @param[in] expression
 *     This is an expression AST node.
 *
 * @return
 *     statement AST node.
 */
T_statement create_statement(T_expression expression);

/**
 * This function creates and returns an expression AST node.
 * To build the expression AST node, it needs below three tokens as the input patameters.
 *      1. An operand token
 *      2. An operator token
 *      3. An operand token
 *
 * @param[in] operand1_token
 *     This is an operand token.
 *
 * @param[in] operator_token
 *     This is an operator token.
 *
 * @param[in] operand2_token
 *     This is an operand token.
 *
 * @return
 *     expression AST node.
 */
T_expression create_expression(T_token operand1_token, T_token operator_token, T_token operand2_token);

/**
 * This function returns the current token which read last time from the lexer. 
 *
 * @return
 *     Current token read from the lexer in the last time.
 */
T_token get_lookahead();

/**
 * Read the next token from lexer and store globally. 
 */
void next_token();

/**
 * This function is for error handling
 * Terminate if it find input does not match with the syntax in the language rules
 */
void parser_error();

#endif