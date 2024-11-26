#include "../inc/BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange(void){
	getData();
	std::cout << "Succesfully loaded in data\n";
}

BitcoinExchange::~BitcoinExchange(void){

}

void BitcoinExchange::getData()
{

	//open the data file
	std::ifstream	dataFile;

	dataFile.open("data.csv", std::ifstream::in);

	if (!dataFile.is_open())
	{
		std::cerr << "Failed to open 'data.csv'" << "\n";
		exit(errno);
	}

	//get the first line and check whether it specifies the allowed format
	std::string	line;
	getline(dataFile, line);

	if (line.empty())
	{
		std::cerr << "error getting line from file\n";
		exit(1);
	}

	if (line != "date,exchange_rate")
	{
		std::cerr << "Data file does not seem to match the format. please make sure it follows the 'date,exchange_rate' format\n";
		exit (1);
	}
	

	//parse the data
	while (dataFile.peek() != EOF)
	{
		std::getline(dataFile, line);

		if (line.empty())
			break ;
		
		auto delimPos = line.find(",");

		//get and validate the date
		std::string	date = line.substr(0, delimPos);
		if (validateDate(date))
			exit(1);

		//get and validate the price
		std::string	price = line.substr(delimPos + 1, line.length() - delimPos - 1);

		float	priceFloat;
		try {
			priceFloat = std::stof(price);
		}
		catch (std::invalid_argument& e){
			std::cerr << "Invalid price argument found in data; see: " << line <<  "\n";
			exit(1);
		}

		//insert date/price combination into the map
		_map.insert(std::make_pair(date, priceFloat));
	}
}

int	BitcoinExchange::validateDate(std::string date)
{
	struct tm time;

	//let strptime validate the date 
	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
	{
		std::cerr << "Wrong date format: " << date << "\n";
		return (1);
	}
	return (0);
}

void	BitcoinExchange::getUserInput(std::string fileName)
{
	std::cout << fileName << "\n";

	std::fstream file;

	file.open(fileName, std::ifstream::in);
	if (!file.is_open())
	{
		std::cerr << "Error, file '" << fileName << "' did not open\n";
		exit (1);
	}

	//get the first line from the input file
	std::string line;
	getline(file, line);
	if (line.empty())
	{
		std::cerr << "error getting line from file\n";
		exit(1);
	}

	//check whether it follows the format
	if (line != "date | value")
	{
		std::cerr << "Input file does not seem to match the format. please make sure it follows the 'date,exchange_rate' format\n";
		exit (1);
	}


	//parse the data
	while (file.peek() != EOF)
	{
		std::getline(file, line);

		if (line.empty())
			break ;
		
		auto delimPos = line.find("|");

		//get and validate the date
		std::string	date = line.substr(0, delimPos - 1);
		if (validateDate(date))
			continue ;

		//get and validate the amount
		std::string	amount = line.substr(delimPos + 1, line.length() - delimPos - 1);
		float	amountFloat;
		try {
			amountFloat = std::stof(amount);
			if (amountFloat < 0 || amountFloat > 1000)
			{
				std::cerr << "Error: too large a number\n";
				continue;
			}
		}
		catch (std::invalid_argument& e){
			std::cerr << "Invalid price argument found in input; see: " << line <<  "\n";
			continue ;
		}

		// //print results
		printResults(date, amountFloat);
	}
}

void BitcoinExchange::printResults(std::string date, float amount)
{
	std::cout << date << " => " << amount << " = " << _map[date] * amount << "\n";
}