#pragma once

class Base {
	private:

	protected:

	public:
		virtual ~Base();
		static Base*	generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);
};