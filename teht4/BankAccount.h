#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
protected:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    double getBalance() const;
    std::string getOwner() const;
};

#endif