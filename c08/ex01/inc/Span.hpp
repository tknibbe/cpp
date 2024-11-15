#pragma once
#include <exception>
#include <vector>


class Span {
	private:
		const unsigned int	_maxN = 0;
		std::vector<int>	_numbers;
		
	protected:

	public:
		Span(int N);
		~Span();
		Span(const Span& other);
		Span&	operator=(const Span& other);

		void	addNumber(int newNumber);
		int		shortestSpan();
		int		longestSpan();
		void	print();

		template <typename Iter>
		void	addNumber(Iter begin, Iter end){
			
			if (std::distance(begin, end) > static_cast<std::ptrdiff_t>(_maxN - _numbers.size()))
				throw storageLimitExceeded();

			_numbers.insert(_numbers.end(), begin, end);
		}


		class noSpanToBeFound : public std::exception
		{
			const char *what() const throw(){
				return ("Amount of numbers in Span is too small to calculate a span. (less or equal to one)\n");
			}
		};
		class storageLimitExceeded : public std::exception
		{
			const char *what() const throw(){
				return ("Storage limit of span reached. not adding number to Span\n");
			}
		};
};
