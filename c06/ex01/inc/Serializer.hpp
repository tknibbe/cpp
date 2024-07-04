#pragma once
#include <cstdint>

class Data;

class Serializer {
	private:

	protected:

	public:
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer&	operator=(const Serializer& other) = delete;
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
