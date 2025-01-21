#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include <iostream>
#include <string>
#include "chef.h"

using namespace std;

class ItalianChef : public Chef {
private:
    string password = "pizza";
    int flour;
    int water;

    int makePizza();

public:
    ItalianChef(const string& name);
    ~ItalianChef();
    bool askSecret(const string& inputPassword, int flourAmount, int waterAmount);
};

#endif // ITALIANCHEF_H