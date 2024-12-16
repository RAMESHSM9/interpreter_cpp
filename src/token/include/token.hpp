#pragma once

#include <string>
#include <map>
#include <constants.hpp>
#include <iostream>
using namespace std;

namespace interpreter
{

	// @ Token Data structure
	// @ Token can be of type like - =+(){}...
	// @ Token has values like 5,10...
	class Token
	{
	public:
		Token();
		Token(TokenType type, std::string literal);

		~Token();

		void setTokenType(TokenType tokenType);

		void setTokenLiteral(std::string literal);

		TokenType getTokenType();

		std::string getTokenLiteral();

		TokenType lookupIdentifier(const std::string &identifier);

	private:
		void populateKeyWords();
		TokenType _type;
		std::string _literal;
		std::map<std::string, TokenType> keyWords;

		static std::string toString(TokenType type)
		{
			switch (type)
			{
			case ILLEGAL:
				return "ILLEGAL";
			case EOF_TOKEN:
				return "EOF_TOKEN";
			case IDENT:
				return "IDENT";
			case INT:
				return "INT";
			case ASSIGN:
				return "ASSIGN";
			case PLUS:
				return "PLUS";
			case MINUS:
				return "MINUS";
			case BANG:
				return "BANG";
			case ASTERISK:
				return "ASTERISK";
			case SLASH:
				return "SLASH";
			case LT:
				return "LT";
			case GT:
				return "GT";
			case EQ:
				return "EQ";
			case NOT_EQ:
				return "NOT_EQ";
			case LPAREN:
				return "LPAREN";
			case RPAREN:
				return "RPAREN";
			case LBRACE:
				return "LBRACE";
			case RBRACE:
				return "RBRACE";
			case COMMA:
				return "COMMA";
			case SEMICOLON:
				return "SEMICOLON";
			case FUNCTION:
				return "FUNCTION";
			case LET:
				return "LET";
			case TRUE:
				return "TRUE";
			case FALSE:
				return "FALSE";
			case IF:
				return "IF";
			case ELSE:
				return "ELSE";
			case RETURN:
				return "RETURN";
			default:
				return "UNKNOWN";
			}
		}

		//@ friends
	public:
		friend ostream &operator<<(ostream &out, const Token &tok)
		{
			// print format: {Type:let Literal:val}
			out << "{ Type: " << Token::toString(tok._type) << " Literal: " << tok._literal << " }" << endl;
			return out;
		}
	};

}
