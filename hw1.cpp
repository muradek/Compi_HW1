#include "tokens.hpp"
#include <iostream>

extern struct loc_t {int from; int to; } yyloc;

const char* getTokenType(int token_num)
{
	switch(token_num)
	{
		case INT: return "INT";
		case BYTE: return "BYTE";
    case B: return "B";
    case BOOL: return "BOOL";
    case AND: return "AND";
    case OR: return "OR";
    case NOT: return "NOT";
    case TRUE: return "TRUE";
    case FALSE: return "FALSE";
    case RETURN: return "RETURN";
    case IF: return "IF";
    case ELSE: return "ELSE";
    case WHILE: return "WHILE";
    case BREAK: return "BREAK";
    case CONTINUE: return "CONTINUE";
    case SC: return "SC";
    case LPAREN: return "LPAREN";
    case RPAREN: return "RPAREN";
    case LBRACE: return "LBRACE";
    case RBRACE: return "RBRACE";
    case ASSIGN: return "ASSIGN";
    case RELOP: return "RELOP";
    case BINOP: return "BINOP";
    case COMMENT: return "COMMENT";
		case ID: return "ID";
    case NUM: return "NUM";
    case STRING: return "STRING";
	}
  return "Failed";
}

void printRequestedLine(int token_num)
{
  const char* token_type = getTokenType(token_num);
  switch(token_num)
	{
		case COMMENT: 
      std::cout << yylineno << " " << token_type << " //" << std::endl;
      break;

    default:
      std::cout << yylineno << " " << token_type << " " << yytext << std::endl;
      break;
  }
}

int main()
{
	int token;
	while(token = yylex()) 
	{
		printRequestedLine(token);
	}
	return 0;
}