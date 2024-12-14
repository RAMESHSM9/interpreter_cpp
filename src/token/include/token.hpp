#pragma once

#include <string>
#include <constants.hpp>

namespace interpreter
{

	// @ Token Data structure
	// @ Token can be of type like - =+(){}...
	// @ Token has values like 5,10...
	class Token
	{
	public:
		Token(TokenType type, std::string literal);

		~Token();

		void setTokenType(TokenType tokenType);

		void setTokenLiteral(std::string literal);

		TokenType getTokenType();

		std::string getTokenLiteral();

	private:
		TokenType _type;
		std::string _literal;
	};

}
