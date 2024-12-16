#pragma once
#include <iostream>

namespace interpreter
{
	class Repl
	{
	public:
		void start(std::istream &in, std::ostream &out);
	};
}