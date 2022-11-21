#include <iostream>
#include <vector>
#include <string>

#include "MyBankAccount.h"
#include "MyBankCustomer.h"
#include "MyBankBankLogic.h"
#include "MyBankCreditAccount.h"

void intro();
void doWhileIntro();
	
std::string cinCustomerName(std::string& name);
std::string cinCustomerSurname(std::string& surname);
std::string cinPersonalNumber(std::string& pNo);

int cinValidAccountId(int& accountId);
int cinValidAmount(int& amount);
int bankLoop(BankLogic& myBank);
