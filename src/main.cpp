#include <iostream>
#include <string>
#include <repl.hpp>
using namespace std;

using namespace interpreter;

int main()
{
	Repl readEvalPrintAndLoopInstance;
	try
	{
		std::cout << "Hello! This is the Monkey programming language!" << std::endl;
		std::cout << "Feel free to type in commands" << std::endl;
		readEvalPrintAndLoopInstance.start(std::cin, std::cout);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}