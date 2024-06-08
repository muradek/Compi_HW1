#include "tokens.hpp"
#include <iostream>
#include <string.h>
#include <string>

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



const char* getString(const char* src_str)
{
  const char* subStr = strndup(src_str + 1, strlen(src_str)-2); //removing the "" 
  return subStr;
}

void printRequestedLine(int token_num)
{
  const char* token_type = getTokenType(token_num);
  switch(token_num)
	{
		case COMMENT: 
      std::cout << yylineno << " " << token_type << " //" << std::endl;
      break;

    case STRING:
      if (strlen(yytext)==2) //empty string ""
      {
        std::cout << yylineno << " " << token_type << std::endl;
      }
      else
      {
        const char* subStr = getString(yytext); //remove ""
        std::cout << yylineno << " " << token_type << " " << subStr << std::endl;
      }
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
    if (token == -1)
    {
      std::cout << "Error " << yytext << std::endl;
      exit(0);
    }
		printRequestedLine(token);
	}
	return 0;
}