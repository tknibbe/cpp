#pragma once

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <ctime> //for validating dates

class BitcoinExchange {
	private:
		std::map<std::string, float>	_map;
		void	getData();

	protected:

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other) = delete;
		BitcoinExchange&	operator=(const BitcoinExchange& other) = delete;

		int	validateDate(std::string date);
		void	getUserInput(std::string file);
		void	printResults(std::string date, float amount);
};
