#pragma once

#include <string>

namespace interpreter
{
	//@ token types
	enum TokenType
	{
		ILLEGAL,
		EOF_TOKEN,

		//@ identifiers
		IDENT,
		INT,

		//@operators
		ASSIGN,
		PLUS,

		//@ delimiters
		LPAREN,
		RPAREN,
		LBRACE,
		RBRACE,
		COMMA,
		SEMICOLON,

		// Keywords
		FUNCTION,
		LET
	};
}
