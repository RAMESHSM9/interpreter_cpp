#pragma once

#include <string>
#include <map>
#include <constants.hpp>

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
	};

}
