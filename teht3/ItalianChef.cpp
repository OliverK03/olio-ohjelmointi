#include "italianchef.h"
#include <iostream>
#include <string>

using namespace std;

ItalianChef::ItalianChef(const std::string& name) : Chef(name), flour(0), water(0) 
{
    cout << "ItalianChef constructor called. Todays chef's name is: " << chefName << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef destructor called. End of duty for our chef called: " << chefName << endl;
}

bool ItalianChef::askSecret(const std::string& inputPassword, int floutAmount, int waterAmount) {
    if (inputPassword == password) {
        cout << "The password is correct. Let's make a pizza!" << endl;
        flour = floutAmount;
        water = waterAmount;
        makePizza();
        return true;
    } else {
        cout << "The password is incorrect. No pizza for non-italians!!" << endl;
        return false;
    }
}

int ItalianChef::makePizza() {
    cout << "Making pizza with " << flour << " grams of flour and " << water << " dl of water." << endl;
    int maxPizzasByFlour = flour / 5;
    int maxPizzasByWater = water / 5;
    int pizzasMade = min(maxPizzasByFlour, maxPizzasByWater);

    flour -= pizzasMade * 5;
    water -= pizzasMade * 5;

    cout << "Pizza(s) made: " << pizzasMade << endl;
    cout << "Flour left: " << flour << " grams" << endl;
    cout << "Water left: " << water << " dl" << endl;

    return pizzasMade;
}
