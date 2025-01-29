#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BankAccount.h"
#include "CreditAccount.h"

class Customer {
private:
    std::string name;
    BankAccount bankAccount;
    CreditAccount creditAccount;

public:
    Customer(const std::string& name, double creditLimit);
    std::string getName() const;
    void showBalance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
    bool payCredit(double amount);
    bool withdrawCredit(double amount);
    bool transfer(double amount, Customer& target);
};

#endif