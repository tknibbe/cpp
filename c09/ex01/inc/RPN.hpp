#pragma once

#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int>	_stack;

	protected:

	public:
		RPN() = default;
		~RPN() = default;
		RPN(const RPN& other) = delete;
		RPN&	operator=(const RPN& other) = delete;

		void	calculate(std::string input);
		void	doCalculation(std::string token);
};
