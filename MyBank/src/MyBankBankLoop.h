#include <iostream>
#include <vector>
#include <string>

#include "MyBankAccount.h"
#include "MyBankCustomer.h"
#include "MyBankBankLogic.h"

void intro();
void doWhileIntro();
	
std::string cinCustomerName();
std::string cinCustomerSurname();
std::string cinPersonalNumber();

int cinValidAccountId();
int cinValidAmount();
int bankLoop(BankLogic myBank);
