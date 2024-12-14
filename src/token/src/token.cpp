#include <token.hpp>

namespace interpreter
{

	Token::Token(TokenType type, std::string literal) : _type(type), _literal(literal) {}
	Token::~Token()
	{
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

}