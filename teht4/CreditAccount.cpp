#include "CreditAccount.h"
#include <iostream>

CreditAccount::CreditAccount(const std::string& owner, double creditLimit) 
    : BankAccount(owner), creditLimit(creditLimit) {}

bool CreditAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Deposit amount must be positive." << std::endl;
        return false;
    }
    balance += amount;
    if (balance > 0) {
        balance = 0; // Credit account balance cannot be positive
    }
    return true;
}

bool CreditAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive." << std::endl;
        return false;
    }
    if (balance - amount < -creditLimit) {
        std::cout << "Credit limit exceeded." << std::endl;
        return false;
    }
    balance -= amount;
    return true;
}

double CreditAccount::getRemainingCredit() const {
    return creditLimit + balance;
}