#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "BankAccount.h"

class CreditAccount : public BankAccount {
private:
    double creditLimit;

public:
    CreditAccount(const std::string& owner, double creditLimit);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
    double getRemainingCredit() const;
};

#endif