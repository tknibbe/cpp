#pragma once

#include <array>
#include <string>

#define brainNumIdeas 100

class Brain {
	private:
		std::string *_ideas[brainNumIdeas];
	protected:

	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain&		operator=(const Brain& other);
		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index);};
