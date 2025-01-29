#include "Customer.h"
#include <iostream>
#include <string>

int main() {
    std::string name1, name2;
    double creditLimit1, creditLimit2;

    // Input for the first customer
    std::cout << "Enter the name of the first customer: ";
    std::getline(std::cin, name1);
    std::cout << "Enter the credit limit for " << name1 << ": ";
    std::cin >> creditLimit1;
    std::cin.ignore(); // Clear the newline character from the input buffer

    // Input for the second customer
    std::cout << "Enter the name of the second customer: ";
    std::getline(std::cin, name2);
    std::cout << "Enter the credit limit for " << name2 << ": ";
    std::cin >> creditLimit2;
    std::cin.ignore(); // Clear the newline character from the input buffer

    // Create customer objects
    Customer customer1(name1, creditLimit1);
    Customer customer2(name2, creditLimit2);

    // Demonstrate operations for the first customer
    std::cout << "\n--- Operations for " << customer1.getName() << " ---" << std::endl;
    double depositAmount, withdrawalAmount;

    std::cout << "Enter deposit amount for " << customer1.getName() << ": ";
    std::cin >> depositAmount;
    customer1.deposit(depositAmount);

    std::cout << "Enter withdrawal amount for " << customer1.getName() << ": ";
    std::cin >> withdrawalAmount;
    customer1.withdraw(withdrawalAmount);

    std::cout << "Enter credit withdrawal amount for " << customer1.getName() << ": ";
    std::cin >> withdrawalAmount;
    customer1.withdrawCredit(withdrawalAmount);

    customer1.showBalance();

    // Demonstrate operations for the second customer
    std::cout << "\n--- Operations for " << customer2.getName() << " ---" << std::endl;

    std::cout << "Enter deposit amount for " << customer2.getName() << ": ";
    std::cin >> depositAmount;
    customer2.deposit(depositAmount);

    std::cout << "Enter withdrawal amount for " << customer2.getName() << ": ";
    std::cin >> withdrawalAmount;
    customer2.withdraw(withdrawalAmount);

    std::cout << "Enter credit withdrawal amount for " << customer2.getName() << ": ";
    std::cin >> withdrawalAmount;
    customer2.withdrawCredit(withdrawalAmount);

    customer2.showBalance();

    // Demonstrate transfer between customers
    double transferAmount;
    std::cout << "\n--- Transfer from " << customer1.getName() << " to " << customer2.getName() << " ---" << std::endl;
    std::cout << "Enter transfer amount: ";
    std::cin >> transferAmount;

    if (customer1.transfer(transferAmount, customer2)) {
        std::cout << "Transfer successful!" << std::endl;
    } else {
        std::cout << "Transfer failed." << std::endl;
    }

    // Show final balances
    std::cout << "\n--- Final Balances ---" << std::endl;
    std::cout << customer1.getName() << ":" << std::endl;
    customer1.showBalance();
    std::cout << customer2.getName() << ":" << std::endl;
    customer2.showBalance();

    return 0;
}