// The cpp file needs DECLARATIONS from the header file

#include "MyBankBankLoop.h"

using namespace std;

// Instantiate private static vectors and variables
vector<Account> Customer::myAccounts;

Customer::Customer(std::string& name, std::string& surname, std::string& pNo) {
	this->customerName = name;
	this->customerSurname = surname;
	this->personalNumber = pNo;
}

void Customer::setCustomerName(std::string& newName) {
	this->customerName = newName;
}

void Customer::setCustomerSurname(std::string& newSurname) {
	this->customerSurname = newSurname;
}

void Customer::setPersonalNumber(std::string& newPersonalNumber) {
	this->personalNumber = newPersonalNumber;
}

std::string Customer::getPersonalNumber() {
	return this->personalNumber;
}

std::string Customer::getCustomerInfo() {
	return customerName + " " + customerSurname + " " + personalNumber;
}

int Customer::createAccount() {
	Account newAccount;
	this->myAccounts.push_back(newAccount);
	return newAccount.getAccountNumber();
}

std::vector<std::string> Customer::getAllAccountsAsStrings() {
	std::vector<std::string> allAccounts;
	for (Account& a : myAccounts) {
		int aAccNum = a.getAccountNumber();
		allAccounts.push_back(this->getAccountAsString(aAccNum));
	}
	return allAccounts; 
}

bool Customer::setBalance(int& accountId, int& amount) {
	for (Account& a : myAccounts) {
		if (a.getAccountNumber() == accountId) {
			a.setBalance(amount);
			return true;
		}
	}
	return false;
}

std::string Customer::closeAccount(int& accountId) {
	int i = 0;
	for (Account& a : myAccounts) {
		if (a.getAccountNumber() == accountId) {
			std::string closedAccount = this->getCalculatedAccountAsString(accountId);
			myAccounts.erase(myAccounts.begin()+i);
			return closedAccount;
		}
		i++;
	}
	return "";
}

// PRIVATE METHODS

std::string Customer::getAccountAsString(int& accountId) {
	for (Account& a : myAccounts) {
		if (a.getAccountNumber() == accountId) {
			return to_string(a.getBalance())
				+ " "
				+ to_string(a.getAccountNumber())
				+ " "
				+ a.getAccountType()
				+ " "
				+ to_string(a.getInterest());
		}
	}
	return "";
}

std::string Customer::getCalculatedAccountAsString(int& accountId) {
	for (Account& a : myAccounts) {
		if (a.getAccountNumber() == accountId) {
			return to_string(a.getBalance() + a.getInterest() * a.getBalance())
				+ " "
				+ to_string(a.getAccountNumber())
				+ " "
				+ a.getAccountType()
				+ " Interest: "
				+ to_string(a.getInterest()*a.getBalance());
		}
	}
	return "";
}