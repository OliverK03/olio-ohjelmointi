#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, double creditLimit) 
    : name(name), bankAccount(name), creditAccount(name, creditLimit) {}

std::string Customer::getName() const {
    return name;
}

void Customer::showBalance() const {
    std::cout << "Bank Account Balance: " << bankAccount.getBalance() << std::endl;
    std::cout << "Remaining Credit: " << creditAccount.getRemainingCredit() << std::endl;
}

bool Customer::deposit(double amount) {
    return bankAccount.deposit(amount);
}

bool Customer::withdraw(double amount) {
    return bankAccount.withdraw(amount);
}

bool Customer::payCredit(double amount) {
    return creditAccount.deposit(amount);
}

bool Customer::withdrawCredit(double amount) {
    return creditAccount.withdraw(amount);
}

bool Customer::transfer(double amount, Customer& target) {
    if (amount <= 0) {
        std::cout << "Transfer amount must be positive." << std::endl;
        return false;
    }
    if (!bankAccount.withdraw(amount)) {
        std::cout << "Transfer failed: Insufficient balance." << std::endl;
        return false;
    }
    if (!target.deposit(amount)) {
        bankAccount.deposit(amount); // Rollback if deposit fails
        std::cout << "Transfer failed: Target deposit error." << std::endl;
        return false;
    }
    return true;
}