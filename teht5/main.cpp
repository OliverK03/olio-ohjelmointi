#include "Notificator.h"

int main() {
    Notificator notificator;
    Follower* a = new Follower("A");
    Follower* b = new Follower("B");
    Follower* c = new Follower("C");

    notificator.add(a);
    notificator.add(b);
    notificator.add(c);

    notificator.printFollowers();
    notificator.notify("This is message 1");

    notificator.remove("B");
    notificator.notify("This is message 2");

    delete a;
    delete b;
    delete c;

    return 0;
}