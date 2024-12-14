#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "../../src/token/include/token.hpp"
#include "../../src/lexer/include/lexer.hpp"

using namespace std;
namespace interpreter::test
{
	TEST(LexerTest, TestNextToken)
	{
		std::string input = R"(let five = 5;
							   let ten = 10;
							   let add = fn(x, y) {x + y;};
							   let result = add(five, ten);
							)";

		std::vector<std::pair<TokenType, std::string>> expectedTokenSet = {
			{LET, "let"},
			{IDENT, "five"},
			{ASSIGN, "="},
			{INT, "5"},
			{SEMICOLON, ";"},
			{LET, "let"},
			{IDENT, "ten"},
			{ASSIGN, "="},
			{INT, "10"},
			{SEMICOLON, ";"},
			{LET, "let"},
			{IDENT, "add"},
			{ASSIGN, "="},
			{FUNCTION, "fn"},
			{LPAREN, "("},
			{IDENT, "x"},
			{COMMA, ","},
			{IDENT, "y"},
			{RPAREN, ")"},
			{LBRACE, "{"},
			{IDENT, "x"},
			{PLUS, "+"},
			{IDENT, "y"},
			{SEMICOLON, ";"},
			{RBRACE, "}"},
			{SEMICOLON, ";"},
			{LET, "let"},
			{IDENT, "result"},
			{ASSIGN, "="},
			{IDENT, "add"},
			{LPAREN, "("},
			{IDENT, "five"},
			{COMMA, ","},
			{IDENT, "ten"},
			{RPAREN, ")"},
			{SEMICOLON, ";"},
			{EOF_TOKEN, ""}};

		Lexer l(input);

		for (size_t i = 0; i < expectedTokenSet.size(); ++i)
		{

			std::unique_ptr<Token> tok = l.NextToken();

			EXPECT_EQ(tok->getTokenType(), expectedTokenSet[i].first) << "tests[" << i << "] - tokentype wrong. expected=" << expectedTokenSet[i].first << ", got=" << tok->getTokenType();

			EXPECT_EQ(tok->getTokenLiteral(), expectedTokenSet[i].second) << "tests[" << i << "] - literal wrong. expected=" << expectedTokenSet[i].second << ", got=" << tok->getTokenLiteral();
		}
	}
};
