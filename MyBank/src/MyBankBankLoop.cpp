// Only the header file is needed to be imported

#include "MyBankBankLoop.h"

using namespace std;

void intro() {
	// Program starts
	cout << "\t\t Hi! Welcome to Bank of Allegendaro! \t\t" << endl;
	cout << endl;
	cout << "\t As Head of Systems, you have access to all our customer information. \t\t" << endl;
}
void doWhileIntro() {
	cout << "\t What action do you wish to perform? \t\t" << endl;
	cout << endl;
	cout << "\t 1. Create new customer" << endl;
	cout << "\t 2. Obtain personal information from all customers" << endl;
	cout << "\t 3. Create an account for a specific customer" << endl;
	cout << "\t 4. Obtain all information, including accounts, from a specific customer" << endl;
	cout << "\t 5. Change name and/or surname of customer" << endl;
	cout << "\t 6. Deposit money to specific account" << endl;
	cout << "\t 7. Withdraw money from specific account" << endl;
	cout << "\t 8. Close an account for a specific customer" << endl;
	cout << "\t 9. Change customer personal number (password required)" << endl;

	cout << "\t 0. Exit program" << endl;
}

std::string cinCustomerName(string& name) {
	do {
		cout << "\t Please, enter your name: " << endl;
		cin >> name;
		return name;
	} while (cin);
}
std::string cinCustomerSurname(string& surname) {
	do {
		cout << "\t Please, enter your surname: " << endl;
		cin >> surname;
		return surname;
	} while (cin);
}
std::string cinPersonalNumber(string& pNo) {
	do {
		cout << "\t Please, enter your personal number: " << endl;
		cin >> pNo;
		return pNo;
	} while (cin);
}

int cinValidAccountId(int& accountId) {
	cout << "\t Please, enter the account id to deposit money into: " << endl;
	cin >> accountId;
	return accountId;
}
int cinValidAmount(int& amount) {
	cout << "\t Please, enter the amount to deposit: " << endl;
	cin >> amount;
	return amount;
}


int bankLoop(BankLogic& myBank) {

	intro();

	int systemChoice;

	do {

		// Declerations
		int *accountId = new int;
		int *amount = new int;

		std::string *name = new string;
		std::string *surname = new string;
		std::string *personalNumber = new string;
		std::string closeAccountTest;
		std::string *password = new string;
		
		std::vector<std::string> *cWithAccounts = new std::vector<std::string>;

		doWhileIntro();

		cin >> systemChoice;

		switch (systemChoice) {
		case 1:
			*name = cinCustomerName(*name);
			*surname = cinCustomerSurname(*surname);
			*personalNumber= cinPersonalNumber(*personalNumber);

			if (myBank.createCustomer(*name, *surname, *personalNumber)) {
				cout << "\n\t Success! Your customer har been created. \n\n";
			}
			else {
				cout << "\t Sorry, customer already exists! \n\n\n";
			}

			delete name;
			delete surname;
			delete personalNumber;

			break;

		case 2:
			if (myBank.getAllCustomers().size() != 0) {
				cout << "\n\t\t All customer information: \n";
				for (string c : myBank.getAllCustomers()) {
					cout << "\t " << c << "\n";
				}
				cout << "\n\n";
			}
			else {
				cout << "\t You haven't created any customers yet. You can do that by pressing 1 in the main menu! \n \n";
			}
			break;

		case 3:
			*personalNumber= cinPersonalNumber(*personalNumber);		

			if (myBank.createSavingsAccount(*personalNumber) != -1) {
				cout << "\t Account creation has been successfull! \n\n";
			}
			else {
				cout << "\t Customer not found, account has not been created.";
			}

			delete personalNumber;

			break;

		case 4:
			*personalNumber = cinPersonalNumber(*personalNumber);
			*cWithAccounts = myBank.getCustomer(*personalNumber);

			if (cWithAccounts->size() != 0) {
				cout << "\t\t Customer information - Balance, Account number, Account type, Interest rate:\n";
				for (std::string& info : *cWithAccounts) {
					cout << "\t " << info << endl;
				}
				cout << "\n\n";
			}
			else {
				cout << "\t Customer does not exist. Try again or try adding one in the main menu! \n\n";
			}

			delete personalNumber;
			delete cWithAccounts;

			break;

		case 5:
			cout << "\t Please, enter the new name, the new surname and the 10 digit personal number: \n";

			*name = cinCustomerName(*name);
			*surname = cinCustomerSurname(*surname);
			*personalNumber = cinPersonalNumber(*personalNumber);

			if (myBank.changeCustomerName(*name, *surname, *personalNumber)) {
				cout << "\n\t Success! The name has been updated! \n\n";
			}
			else {
				cout << "\n\t Customer not found. Name has not been changed.\n\n";
			}

			delete name;
			delete surname;
			delete personalNumber;

			break;

		case 6:
			cout << "\t Please, enter personal number, account number and amount to deposit: \n";

			*personalNumber = cinPersonalNumber(*personalNumber);
			*accountId = cinValidAccountId(*accountId);
			*amount = cinValidAmount(*amount);

			if (myBank.deposit(*personalNumber, *accountId, *amount)) {
				cout << "\n\t Success! You money has been deposited!\n\n";
			}
			else {
				cout << "\n\t Customer or account not valid. No action was made. \n\n";
			}

			delete accountId;
			delete amount;
			delete personalNumber;

			break;

		case 7:
			cout << "\t Please, enter personal number, account number and amount to withdraw: \n";

			*personalNumber = cinPersonalNumber(*personalNumber);
			*accountId = cinValidAccountId(*accountId);
			*amount = cinValidAmount(*amount);

			if (myBank.withdraw(*personalNumber, *accountId, *amount)) {
				cout << "\n\t Success! You money has been withdrawn!\n\n";
			}
			else {
				cout << "\n\t Customer or account not valid. No action was made. \n\n";
			}

			delete name;
			delete surname;
			delete personalNumber;
			
			break;

		case 8:
			cout << "\t Please, enter personal number and account number of the account that should close. \n";

			*personalNumber = cinPersonalNumber(*personalNumber);
			*accountId = cinValidAccountId(*accountId);

			closeAccountTest = myBank.closeAccount(*personalNumber, *accountId);
			if (closeAccountTest != "") {
				cout << "\n\t Success! Your account has been closed. Here are the details: \n";
				cout << "\t " << closeAccountTest << "\n\n";
			}
			else {
				cout << "\n\t Sorry, customer or account not found. No action was made. \n\n";
			}

			delete accountId;
			delete personalNumber;

			break;

		case 9:
			cout << "\t BE AWARE: This procedure is in need of a password in order to get executed!\n";
			
			*personalNumber = cinPersonalNumber(*personalNumber);

			cout << "\t Please, enter your password: \n";
			cin >> *password;

			if (myBank.changeCustomerPersonalNumber(*personalNumber, *password)) {
				cout << "\n\t Success! Your personal number has been updated!\n\n";
			}
			else {
				cout << "\n\t Apologies, we cannot change your personal number.";
			}

			delete personalNumber;

			break;

		}
	} while (systemChoice != 0);
	cout << "\n\t See you next time! \n";
	return 0;
}