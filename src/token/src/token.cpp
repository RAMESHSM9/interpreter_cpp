#include <token.hpp>
#include <iostream>

namespace interpreter
{
	Token::Token()
	{
		populateKeyWords();
	}
	Token::Token(TokenType type, std::string literal) : _type(type), _literal(literal)
	{
		populateKeyWords();
	}
	Token::~Token()
	{
	}

	void Token::populateKeyWords()
	{
		keyWords["let"] = LET;
		keyWords["fn"] = FUNCTION;
		keyWords["if"] = IF;
		keyWords["else"] = ELSE;
		keyWords["return"] = RETURN;
		keyWords["true"] = TRUE;
		keyWords["false"] = FALSE;
	}
	void Token::setTokenType(TokenType tokenType)
	{
		_type = tokenType;
	}

	void Token::setTokenLiteral(std::string literal)
	{
		_literal = literal;
	}

	TokenType Token::getTokenType()
	{
		return _type;
	}

	std::string Token::getTokenLiteral()
	{
		return _literal;
	}

	TokenType Token::lookupIdentifier(const std::string &identifier)
	{
		if (keyWords.count(identifier) > 0)
		{
			return keyWords[identifier];
		}
		return IDENT;
	}

}