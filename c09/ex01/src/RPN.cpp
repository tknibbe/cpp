#include "../inc/RPN.hpp"
#include <iostream>
#include <sstream>


static bool isValidOperator(std::string token)
{
	if (token.length() > 1)
	{
		std::cerr << "Error, token is too long! see '" << token << "'\n";
		exit(1);
	}

	std::string set("+-/*");
	if (set.find(token) == std::string::npos)
	{
		std::cerr << "Error, Illegal token found at '" << token << "'\n";
		exit(1);
	}
	return (true);
}

static bool isValidNumber(std::string token)
{
	if (token.length() > 1)
	{
		std::cerr << "Error, token is too long! see '" << token << "'\n";
		exit(1);
	}

	if (isdigit(token[0]))
		return (true);

	return false;
}

void	RPN::doCalculation(std::string token)
{
	if (_stack.size() < 2)
	{
		std::cerr << "Error, not enough operands on stack to do operation\n";
		exit(1);
	}

	//get top 2 operands
	int operand1 = _stack.top();
	_stack.pop();
	int operand2 = _stack.top();
	_stack.pop();


	//do operation
	switch (token[0])
	{
		case '*' :
			_stack.push(operand2 * operand1);
			break ;
		
		case '+':
			_stack.push(operand2 + operand1);
			break ;

		case '-':
			_stack.push(operand2 - operand1);
			break ;

		case '/':
			if (operand1 == 0 || operand2 == 0)
			{
				std::cerr << "Please dont divide by zero\n";
				exit (1);
			}
			_stack.push(operand2 / operand1);
			break ;
	}

	//uncomment for step by step 
	// std::cout << operand2 << token << operand1 << " = " << _stack.top() <<  "\n";
}


void RPN::calculate(std::string input)
{
	std::stringstream	stream(input);
	std::string			token;
	
	//while we have token
	while (stream.peek() != EOF)
	{
		std::getline(stream, token, ' ');
		if (!stream)
		{
			std::cerr << "Reading from stream went wrong\n"; 
			exit (1);
		}
		if (token.empty())
			continue;

		//if its a valid number add it to the stack
		if (isValidNumber(token))
			_stack.push(std::stoi((token)));
		//if its a valid operator, do the calculation
		else if (isValidOperator(token))
			doCalculation(token);
	}

	//if there is more than 1 number left on the stack
	if (_stack.size() != 1)
	{
		std::cerr << "Error doing calculations. not enough operands\n";
		exit(1);
	}

	std::cout << _stack.top();
}