// Header files does the DECLERATION for the cpp file

class Customer {
private:
	std::string customerName;
	std::string customerSurname;
	std::string personalNumber;
	
	static std::vector<Account> myAccounts;

	std::string getAccountAsString(int& accountId);
	std::string getCalculatedAccountAsString(int& accountId);

public:
	//Constructor
	Customer(std::string& name, std::string& surname, std::string& pNo);
	
	void setCustomerName(std::string& newName);
	void setCustomerSurname(std::string& newSurname);
	void setPersonalNumber(std::string& newPersonalNumber);

	std::string getPersonalNumber();
	std::string getCustomerInfo();
	std::string closeAccount(int& accountId);

	int createAccount();

	bool setBalance(int& accountId, int& amount);

	std::vector<std::string> getAllAccountsAsStrings();
};
