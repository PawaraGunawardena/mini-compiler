#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main()
{
    next_token();
    T_statement_list statement_list = parse_statement_list();
    gencode_statement_list(statement_list);

    return 0;
}
