// The cpp file needs DECLARATIONS from the header file

#include "MyBankBankLoop.h"

using namespace std;

// Instantiate protected static variables
int Account::currentAccountNumber = 1001;

Account::Account() {
	this->accountNumber = currentAccountNumber++;
};

void Account::setBalance(int& amount) {
	this->balance = this->balance + amount;
}

void Account::setAccountType(std::string& type) {
	this->accountType = accountType;
}

int Account::getAccountNumber() {
	return this->accountNumber;
}

std::string Account::getAccountType() {
	return this->accountType;
}

double Account::getBalance() {
	return this->balance;
}

double Account::getInterest() {
	return this->interestRate;
}