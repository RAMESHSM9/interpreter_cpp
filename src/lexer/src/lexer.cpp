#include <lexer.hpp>
#include <iostream>
namespace interpreter
{
	namespace
	{
		bool isLetter(char ch)
		{
			return 'A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z' || ch == '_';
		}

		bool isDigit(char ch)
		{
			return '0' <= ch && ch <= '9';
		}

	}
	Lexer::Lexer(std::string &input) : input(input), position(0), readPosition(0)
	{
		//@ required to advances the pointers correctly before we start tokenizing
		readChar();
	}
	void Lexer::skipWhiteSpaces()
	{
		while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
		{
			readChar();
		}
	}

	char Lexer::peekChar()
	{
		if (readPosition >= input.length())
		{
			return 0;
		}
		return input[readPosition];
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

	std::string Lexer::readIdentifier()
	{
		int currPosition = position;
		while (isLetter(ch))
		{
			readChar();
		}
		int length = position - currPosition;
		return input.substr(currPosition, length);
	}

	std::string Lexer::readNumber()
	{
		int currPosition = position;
		while (isDigit(ch))
		{
			readChar();
		}
		int length = position - currPosition;
		return input.substr(currPosition, length);
	}

	std::unique_ptr<Token> Lexer::NextToken()
	{
		std::unique_ptr<Token> tok;
		skipWhiteSpaces();
		switch (ch)
		{
		case '=':
			if (peekChar() == '=')
			{
				readChar();
				tok = std::make_unique<Token>(EQ, "==");
			}
			else
			{
				tok = std::make_unique<Token>(ASSIGN, "=");
			}

			break;
		case '+':
			tok = std::make_unique<Token>(PLUS, "+");
			break;
		case '-':
			tok = std::make_unique<Token>(MINUS, "-");
			break;
		case '!':
			if (peekChar() == '=')
			{
				readChar();
				tok = std::make_unique<Token>(NOT_EQ, "!=");
			}
			else
			{
				tok = std::make_unique<Token>(BANG, "!");
			}
			break;
		case '/':
			tok = std::make_unique<Token>(SLASH, "/");
			break;
		case '*':
			tok = std::make_unique<Token>(ASTERISK, "*");
			break;
		case '<':
			tok = std::make_unique<Token>(LT, "<");
			break;
		case '>':
			tok = std::make_unique<Token>(GT, ">");
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
			//@ identifier/Keyword
			if (isLetter(ch))
			{
				tok = std::make_unique<Token>();
				tok->setTokenLiteral(readIdentifier());
				tok->setTokenType(tok->lookupIdentifier(tok->getTokenLiteral()));
				return tok;
			}
			else if (isDigit(ch))
			{
				tok = std::make_unique<Token>();
				tok->setTokenLiteral(readNumber());
				tok->setTokenType(INT);
				return tok;
			}
			else
			{
				tok = std::make_unique<Token>(ILLEGAL, std::to_string(ch));
			}
		}

		readChar();
		return tok;
	}
}