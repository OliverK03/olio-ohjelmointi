#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(const string& name) : chefName(name) 
{
    cout << "Chef constructor called. Todays chef's name is: " << chefName << endl;
}

Chef::~Chef()
{
    cout << "Chef destructor called. End of duty for our chef called: " << chefName << endl;
}

std::string Chef::getName() const {
    return chefName;
}

int Chef::makeSalad(int ingredients) {
    int servings = ingredients / 5;
    cout << "Making salad with " << ingredients << " ingredients. " << servings << " servings made." << endl;
    return servings;
}

int Chef::makeSoup(int ingredients) {
    int servings = ingredients / 3;
    cout << "Making soup with " << ingredients << " ingredients. " << servings << " servings made." << endl;
    return servings;
}