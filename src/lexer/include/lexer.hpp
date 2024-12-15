#pragma once
#include <string>
#include <token.hpp>
#include <memory>

namespace interpreter
{
	class Lexer
	{
	public:
		Lexer(std::string &input);

		std::unique_ptr<Token> NextToken();

	private:
		char peekChar();

		void skipWhiteSpaces();

		void readChar();

		std::string readIdentifier();

		std::string readNumber();

		std::string input;
		int position;
		int readPosition;
		char ch;
	};
}