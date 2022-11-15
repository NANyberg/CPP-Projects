// The cpp file needs DECLARATIONS from the header file

#include "MyBankBankLoop.h"

using namespace std;

// Instantiate private static vector
vector<Customer> BankLogic::myCustomers;

bool BankLogic::createCustomer(std::string& name, std::string& surname, std::string& pNo) {
	
	// Blocks customer for being added if pNo matches other customer
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			return false;
		}
	}

	Customer newCustomer(name, surname, pNo);
	this->myCustomers.push_back(newCustomer);
	return true;
}

std::vector<std::string> BankLogic::getAllCustomers() {
	std::vector<std::string> custVector;
	for (Customer& c : myCustomers) {
		custVector.push_back(c.getCustomerInfo());
	}
	return custVector;
}

std::vector<std::string> BankLogic::getCustomer(string pNo) {
	std::vector<std::string> myCustomer;
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			myCustomer.push_back(c.getCustomerInfo());

			if (c.getAllAccountsAsStrings().size() != 0) {

				std::vector<std::string> customerAccounts = c.getAllAccountsAsStrings();

				myCustomer.insert(myCustomer.end(),
								  customerAccounts.begin(),
								  customerAccounts.end());
				return myCustomer;
			}
			return myCustomer;
		}
	}
	return {};
}

int BankLogic::createSavingsAccount(std::string& pNo) {
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			return c.createAccount();
		}
	}
	return -1;
}

bool BankLogic::changeCustomerName(std::string& name, std::string& surname, std::string& pNo) {
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			if (name != "") {
				c.setCustomerName(name);
			}
			if (surname != "") {
				c.setCustomerSurname(surname);
			}
			if (name == "" && surname == "") {
				return false;
			}
			return true;
		}
	}
	return false;
}

bool BankLogic::changeCustomerPersonalNumber(std::string& pNo, std::string& password) {
	std::string correctPassword = "Ändrapno";
	for (Customer& c: myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			if (password.compare(correctPassword)) {
				std::string newPno;
				cout << "\n \t Password correct. What should the new Personal Number be?: " << endl;
				cin >> newPno;
				c.setPersonalNumber(newPno);
				return true;
			}
			return false;
		}
		return false;
	}
}

bool BankLogic::deposit(std::string& pNo, int& accountId, int& amount) {
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			return c.setBalance(accountId, amount);
		}
	}
	return false;
}

bool BankLogic::withdraw(std::string& pNo, int& accountId, int& amount) {
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			return c.setBalance(accountId, amount);
		}
	}
	return false;
}

std::string BankLogic::closeAccount(std::string& pNo, int& accountId) {
	for (Customer& c : myCustomers) {
		if (c.getPersonalNumber() == pNo) {
			return c.closeAccount(accountId);
		}
	}
	return "";
}