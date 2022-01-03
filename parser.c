#include "parser.h"

T_token lookahead_token;

T_token get_lookahead()
{
    return lookahead_token;
}

void next_token()
{
    lookahead_token = lex();
}

T_statement_list parse_statement_list()
{
    /**
        * parse statement
        * parse statement_list
        * create and return a new statement_list node
    */

    if(END != get_lookahead()->kind)
    {
        T_statement statement = parse_statement();
        T_statement_list statement_list = parse_statement_list();
        return create_statement_list(statement, statement_list);
    }
    else
    {
        return NULL;
    }
}

T_statement parse_statement()
{
    /**
        * parse an expression
        * parse a semicolon
        * create a new statement node
    */
   T_expression expression = parse_expression();

   T_token semicolon = get_lookahead();

    if(SEMICOLON != semicolon->kind)
    {
        parser_error();
    }
    next_token();

    return create_statement(expression);
}

T_expression parse_expression()
{
    /**
        * read operand1
        * read operator
        * read operand2
        * create an expression node
    */ 
    T_token operand1_token = get_lookahead();
    if (NUMBER != operand1_token->kind)
    {
        parser_error();
    }
    next_token();

    T_token operator_token = get_lookahead();
    if (OPERATOR != operator_token->kind)
    {
        parser_error();
    }
    next_token();

    
    T_token operand2_token = get_lookahead();
    if (NUMBER != operand2_token->kind)
    {
        parser_error();
    }
    next_token();

    return create_expression(operand1_token, operator_token, operand2_token);
}

T_statement_list create_statement_list(T_statement statement, T_statement_list statement_list)
{
    T_statement_list new_list = malloc(sizeof(*new_list));
    new_list->statement = statement;
    new_list->statement_list = statement_list;
    return new_list;
}

T_statement create_statement(T_expression expression)
{
    T_statement new_statement = malloc(sizeof(*new_statement));
    new_statement->expression = expression;
    return new_statement;
}

T_expression create_expression(T_token operand1_token, T_token operator_token, T_token operand2_token)
{
    T_expression new_expression = malloc(sizeof(*new_expression));

    new_expression->operand1_token = operand1_token;
    new_expression->operator_token = operator_token;
    new_expression->operand2_token= operand2_token;

    return new_expression;
}

void parser_error()
{
    fprintf(stderr, "parser error.\n");
    exit(1);
}
