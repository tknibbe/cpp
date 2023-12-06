#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//constructor and destructor
Account::Account( int initial_deposit ){
	static int index;
	_amount = initial_deposit;
	_accountIndex = index;
	_nbDeposits = 0;
	index++;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}
Account::~Account(void){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}



// accessing class private data
int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}



//accessing instance private data
void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit;

	_amount +=  deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout	<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount;

	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

int		Account::checkAmount( void ) const{
	return _amount;
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout	<< "account:" << _accountIndex 
				<< ";amount:" << _amount 
				<< ";deposits:" << _nbDeposits 
				<< ";withdrawals:" << _nbWithdrawals 
				<< std::endl;
}



//display timestamp
void	Account::_displayTimestamp( void ){
	std::time_t time = std::time(NULL);
	std::tm		*now = std::localtime(&time);
	char		buf[16];
	std::strftime(buf, 16, "%Y%m%d_%H%M%S", now);
	std::cout << "[" << buf << "] ";
}