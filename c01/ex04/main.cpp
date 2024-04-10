/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tknibbe <tknibbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:53:47 by tknibbe           #+#    #+#             */
/*   Updated: 2024/04/10 18:21:05 by tknibbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

void	errormessage(std::string message)
{
	std::cout << message << std::endl;
	exit(EXIT_FAILURE);
}

std::string getFileAsString(std::string filename)
{
	//setting up infile
	std::ifstream	infile;
	infile.open(filename);
	if (!infile.is_open())
		errormessage("Error, infile did not open");

	// using rdbuf() to load whole file into temp as a stream
	// then assigning the stream as a str into whole_file
	std::string whole_file;
	std::ostringstream temp;
	temp << infile.rdbuf();
	whole_file = temp.str();

	infile.close();
	return whole_file;
}

int main(int argc, char **argv)
{
	if (argc != 4)
		errormessage("Error in input");

	//initialize values
	std::string	filename = argv[1];
	std::string	to_find = argv[2];
	std::string	replacement = argv[3];
	
	// get the data from the file as a string
	std::string	whole_file = getFileAsString(filename);

	//find all occurances of to_find, remove them and insert replacement
	size_t	i = whole_file.find(to_find);
	while (i != whole_file.npos)
	{
		whole_file.erase(i, to_find.length());
		whole_file.insert(i, replacement);
		i = whole_file.find(to_find);
	}
	
	//open outfile with ".replace" as extension. then write new adjusted string into outfile
	std::ofstream	outfile;
	outfile.open(filename + ".replace");
	if (!outfile.is_open())
		errormessage("Error, outfile did not open");
	outfile << whole_file;
	outfile.close();

	return (EXIT_SUCCESS);
}