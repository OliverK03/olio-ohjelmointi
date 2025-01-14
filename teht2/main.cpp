#include <iostream>
#include "game.h"

int main() {
    int maxNumber;
    std::cout << "Enter the maximum number for the game: ";
    std::cin >> maxNumber;

    Game game(maxNumber);
    game.play();

    return 0;
}
