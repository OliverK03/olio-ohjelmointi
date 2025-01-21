#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <string>

using namespace std;

class Chef
{
protected:
    string chefName;

public:
    Chef(const string& name);
    ~Chef();
    string getName() const;
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);
};

#endif // CHEF_H