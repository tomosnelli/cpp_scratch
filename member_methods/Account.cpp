// implementation of account
#include "Account.h"
#include <iostream>

void Account::set_balance(double value){
	balance = value;
}

double Account::get_balance(){
	return balance;
}

void Account::deposit(double value){
	if(value > 0){
		balance += value;
	}
	else {
		std::cout << "Can't deposit negative or 0 amount of funds." << std::endl;
	}
}

double Account::withdraw(double value){
	if(value > balance){
		std::cout << "Not enough funds..." << std::endl;
		return 0.0;
	}
	else {
		balance -= value;
		return value;
	}
}
