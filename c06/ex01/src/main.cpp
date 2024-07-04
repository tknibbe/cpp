#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"
#include <iostream>


int main(void){

	//creating an object
	Data	*data = new Data(42, "Bob");

	std::cout << "Data:\n\tValue: " << data->getValue() <<
				"\n\tName: " << data->getName() << "\n\n";
	std::cout << "Data = " << data << "\n";
	//serialize object to "store" the state of said object
	uintptr_t ptr = Serializer::serialize(data);
	std::cout << "ptr = " << ptr << "\n";
	//note that you cannot use "ptr" to use or interact with the object


	//reinstantiate the Data object into another variable to prove the deserialization works
	Data	*data2 = Serializer::deserialize(ptr);
	std::cout << "data2 = " << data2 << "\n";

	std::cout << "Data2:\n\tValue: " << data2->getValue() <<
				"\n\tName: " << data2->getName() << "\n\n";

	delete data2;
}