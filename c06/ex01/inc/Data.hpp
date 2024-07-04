#pragma once
#include <string>

class Data {
	private:
		int			_value;
		std::string	_name;
	protected:

	public:
		Data() =  delete;
		Data(int value, std::string name);
		~Data();
		Data(const Data& other);
		Data&	operator=(const Data& other);
		int		getValue();
		std::string getName();
};
