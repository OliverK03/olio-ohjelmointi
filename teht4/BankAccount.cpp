#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string& owner) : owner(owner), balance(0) {}

bool BankAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Deposit amount must be positive." << std::endl;
        return false;
    }
    balance += amount;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be positive." << std::endl;
        return false;
    }
    if (balance < amount) {
        std::cout << "Insufficient balance." << std::endl;
        return false;
    }
    balance -= amount;
    return true;
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getOwner() const {
    return owner;
}