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
		void readChar();
		std::unique_ptr<Token> NextToken();

	private:
		std::string input;
		int position;
		int readPosition;
		char ch;
	};
}