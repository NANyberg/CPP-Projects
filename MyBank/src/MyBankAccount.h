// Header files does the DECLERATION for the cpp file

class Account {
protected:
	double balance = 0;
	int accountNumber;
	double interestRate = 0.012;
	static int currentAccountNumber;
	std::string accountType = "Savings Account";
	bool isSavingsAccount = true;

public:
	Account();
	void setBalance(int& amount);
	int getAccountNumber();
	void setAccountType(std::string& type);
	std::string getAccountType();
	double getBalance();
	double getInterest();
};
