#ifndef NOTIFICATOR_H
#define NOTIFICATOR_H

#include <string>
#include <iostream>
#include "Follower.h"

using namespace std;

class Notificator {
private:
    Follower* followers;

public:

    Notificator() : followers(nullptr) {}

    void add(Follower* f) {
        f->setNext(followers);
        followers = f;
        cout << "Notificator added follower " << f->getName() << endl;
     }

    void remove(string name) {
        Follower* current = followers;
        Follower* previous = nullptr;

        while (current != nullptr) {
            if (current->getName() == name) {
                if (previous == nullptr) {
                    followers = current->getNext();
                } else {
                    previous->setNext(current->getNext());
                }
                return;
            }
            previous = current;
            current = current->getNext();
            cout << "Notificator removes follower " << name << endl;
        }
    }

    void printFollowers() {
        Follower* current = followers;
        cout << "Notificator followers: " << endl;
        while (current != nullptr) {
            cout << "Follower " << current->getName() << endl;
            current = current->getNext();
        }
    }

    void notify(string notification) {
        Follower* current = followers;
        cout << "Noticator posts a message: " << endl;
        while (current != nullptr) {
            current->update(notification);
            current = current->getNext();
        }
    }
};

#endif // NOTIFICATOR_H