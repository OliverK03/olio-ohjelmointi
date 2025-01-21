#include "chef.h"
#include "italianchef.h"
#include <iostream>
#include <string>

int main() {
    string chefName;
    cout << "Enter the name of the chef: ";
    cin >> chefName;

    Chef generalChef(chefName);
    
    int saladIngredients, soupIngredients;
    cout << "Enter the number of ingredients for the salad: ";
    cin >> saladIngredients;
    cout << "Enter the number of ingredients for the soup: ";
    cin >> soupIngredients;

    generalChef.makeSalad(saladIngredients);
    generalChef.makeSoup(soupIngredients);


    cout << "\nEnter the name of the Italian chef: ";
    cin.ignore();
    cin >> chefName;

    ItalianChef italianChef(chefName);

    int flour, water;
    string password;
    cout << "Enter the amount of flour: ";
    cin >> flour;
    cout << "Enter the amount of water: ";
    cin >> water;
    cout << "Enter the password: ";
    cin >> password;

    if (italianChef.askSecret(password, flour, water)) {
        cout << "The pizza was made successfully!" << endl;
    } else {
        cout << "No pizza for non-italians." << endl;
    }

    return 0;
}