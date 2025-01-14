#ifndef GAME_H
#define GAME_H

#include <iostream>

using namespace std;

class Game {
private:
    int maxNumber;
    int playerGuess;
    int randomNum;
    int numOfGuesses;

public:
    Game(int maxNumber);
    ~Game();
    void play();
    void printGameResult() const;
};

#endif // GAME_H