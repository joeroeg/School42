#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){

}

Account::Account(int initial_deposit) {

}

Account::~Account( void ) {

}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {

}

void    Account::makeDeposit( int deposit ) {

}

bool    Account::makeWithdrawal(int withdrawal ) {

    return true;
}

int     Account::checkAmount( void ) const {
    return _amount;
}

void    Account::displayStatus( void ) const {

}
