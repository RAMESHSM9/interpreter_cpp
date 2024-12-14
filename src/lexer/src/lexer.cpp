#include <lexer.hpp>

namespace interpreter
{

	Lexer::Lexer(std::string &input) : input(input), position(0), readPosition(0)
	{
		//@ required to advances the pointers correctly before we start tokenizing
		readChar();
	}

	void Lexer::readChar()
	{
		if (readPosition >= input.length())
		{
			ch = 0;
		}
		else
		{
			ch = input[readPosition];
		}
		position = readPosition;
		readPosition++;
	}

	std::unique_ptr<Token> Lexer::NextToken()
	{
		std::unique_ptr<Token> tok;
		switch (ch)
		{
		case '=':
			tok = std::make_unique<Token>(ASSIGN, "=");
			break;
		case '+':
			tok = std::make_unique<Token>(PLUS, "+");
			break;
		case '(':
			tok = std::make_unique<Token>(LPAREN, "(");
			break;
		case ')':
			tok = std::make_unique<Token>(RPAREN, ")");
			break;
		case '{':
			tok = std::make_unique<Token>(LBRACE, "{");
			break;
		case '}':
			tok = std::make_unique<Token>(RBRACE, "}");
			break;
		case ',':
			tok = std::make_unique<Token>(COMMA, ",");
			break;
		case ';':
			tok = std::make_unique<Token>(SEMICOLON, ";");
			break;
		case 0:
			tok = std::make_unique<Token>(EOF_TOKEN, "");
			break;

		default:
			break;
		}

		readChar();
		return tok;
	}
}