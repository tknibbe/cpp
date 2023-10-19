#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit ){
	static int index;
	this->_amount = initial_deposit;
	this->_accountIndex = index;
	index++;
	std::cout << "[timestamp]" << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account(void){

}

static void	displayAccountsInfos( void ){

}