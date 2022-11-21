// Header files does the DECLERATION for the cpp file

class BankLogic {
protected:
	static std::vector<Customer> myCustomers;

public:
	std::vector<std::string> getAllCustomers();
	std::vector<std::string> getCustomer(std::string& pNo);

	std::string closeAccount(std::string& pNo, int& accountId);
	
	bool createCustomer(std::string& name, std::string& surname, std::string& pNo);
	bool changeCustomerName(std::string& name, std::string& surname, std::string& pNo);
	bool changeCustomerPersonalNumber(std::string& pNo, std::string& password);
	bool deposit(std::string& pNo, int& accountId, int& amount);
	bool withdraw(std::string& pNo, int& accountId, int& amount);

	int createSavingsAccount(std::string& pNo);
};
