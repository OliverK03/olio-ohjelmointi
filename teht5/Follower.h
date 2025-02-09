#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <string>
#include <iostream>

using namespace std;

class Follower {
private:
    string name;

public:
    Follower* next;

    Follower(string n) :  name(n), next(nullptr) {}

    string getName() const {
        return name;
    }

    void setNext(Follower* f) {
        next = f;
    }

    Follower* getNext() const {
        return next;
    }

    void update(string notification) {
        cout << "Follower " << name << " received a message: " << notification << endl;
    }
};
#endif // FOLLOWER_H
