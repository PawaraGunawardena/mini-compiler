#ifndef CODEGEN_H
#define CODEGEN_H

#include <assert.h> // assert()
#include <stdbool.h> // true/false

#include "parser.h"

/**
 * This function travel the AST to generate machine/assembly code for statement list.
 *
 * @param[in] statement_list
 *     This is a statement_list node of the AST.
 *
 */
void gencode_statement_list(T_statement_list statment_list);

/**
 * This function generate machine/assembly code for statement.
 *
 * @param[in] statement
 *     This is a statement node of the AST.
 *
 */
void gencode_statement(T_statement statement);

/**
 * This function generate machine/assembly code for expression.
 *
 * @param[in] expression
 *     This is an expression node of the AST.
 *
 */
void gencode_expression(T_expression expression);

#endif