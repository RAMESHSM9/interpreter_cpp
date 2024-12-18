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
		MINUS,
		BANG,	  //!
		ASTERISK, //*
		SLASH,
		LT,
		GT,
		EQ,
		NOT_EQ,

		//@ delimiters
		LPAREN,
		RPAREN,
		LBRACE,
		RBRACE,
		COMMA,
		SEMICOLON,

		// Keywords
		FUNCTION,
		LET,
		TRUE,
		FALSE,
		IF,
		ELSE,
		RETURN
	};
}
