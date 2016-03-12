#include "importExpression.h"
#include "TerminalExpression.h"
#include "Parser.h"

importExpression::importExpression()
{
	noArguments = 1;
	optimisable = 0;
}


importExpression::~importExpression()
{
}

Variable importExpression::evaluate()
{
	Parser p;
	std::shared_ptr<TerminalExpression> t = dynamic_pointer_cast<TerminalExpression>(arguments[0]);
	if (t)
	{
		std::ifstream file(t->getString());
		if (!file.is_open())
			throw new Exception(Exception::ErrorType::FILE_LOAD_ERROR);
		std::stringstream buffer;
		buffer << file.rdbuf();
		p.run(buffer.str());
	}
	else
		throw new Exception(Exception::ErrorType::FILE_LOAD_ERROR);

	return Variable();
}
