#include "codegen.h"

void gencode_statement_list(T_statement_list statment_list)
{
    while(NULL != statment_list)
    {
        gencode_statement(statment_list->statement);
        statment_list = statment_list->statement_list;
    }
}

void gencode_statement(T_statement statement)
{
    gencode_expression(statement->expression);
}

void gencode_expression(T_expression expression)
{
    printf("\n");

    printf("\tmovl $%d, %%eax\n", expression->operand1_token->number); // %% escapes %
    printf("\tmovl $%d, %%ebx\n", expression->operand2_token->number); // %% escapes %

    switch (expression->operator_token->character)
    {
        // For addition, it is always going to add register-A, register-B. 
        case '+':
            printf("\taddl %%ebx, %%eax\n");
            break;

        // For substraction, it is always going to be substract register-A, register-B.
        case '-':
            printf("\tsubl %%ebx, %%eax\n");
            break;

        case '*':
            printf("\timull %%ebx, %%eax\n");
            break;

        case '/':
            printf("\tcdq\n");
            printf("\tidiv %%ebx\n");
            break;

        default:
            // can't happen if parser is correct
            assert(false);
            break;

    }

    printf ("\tmovl %%eax, %%esi\n");
    printf ("\tleaq .LC0(%%rip), %%rdi\n");
    printf ("\tmovl $0, %%eax\n");
    printf ("\tcall printf@PLT\n\n");
}

