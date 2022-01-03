#include "lexer.h"
#include "parser.h"
int main()
{
    next_token();
    T_statement_list statement_list = parse_statement_list();
    return 0;
}
