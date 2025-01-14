#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

Game::Game(int maxNumber) {
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value"  << endl;
    
    this->maxNumber = maxNumber;    
    srand(time(NULL));
    randomNum = 0;
    while (randomNum == 0) {
        randomNum = rand() % maxNumber + 1;
    }
    numOfGuesses = 0;
    playerGuess = 0;
}

Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play() {
    while (playerGuess != randomNum) {
        cout << "Guess a randomly generated number: ";
        cin >> playerGuess;
        ++numOfGuesses;
        if (playerGuess > randomNum) {
            cout << "Guessed number is higher than random number!" << endl;
        } else if (playerGuess < randomNum) {
            cout << "Guessed number is lower than random number!" << endl;
        } else {
            break;
        }
    }
    printGameResult();
}

void Game::printGameResult() const {
    cout << "You guessed the correct number. Correct number was : " << randomNum << endl;
    cout << "Tries used: " << numOfGuesses << endl;
}