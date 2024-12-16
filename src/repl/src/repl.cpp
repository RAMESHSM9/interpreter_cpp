#include <repl.hpp>
#include <string>
#include <lexer.hpp>
#include <token.hpp>
namespace interpreter
{
	const std::string PROMPT = ">>";
	void Repl::start(std::istream &in, std::ostream &out)
	{
		std::string line;
		while (true)
		{
			out << PROMPT;
			if (!std::getline(in, line))
			{
				return;
			}
			Lexer l(line);
			for (std::unique_ptr<Token> tok = l.NextToken(); tok->getTokenType() != EOF_TOKEN; tok = l.NextToken())
			{
				out << *tok << std::endl;
			}
		}
	}
}