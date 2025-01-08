#include <iostream>

using namespace std;

int game(int maxnum)
{
    srand(time(NULL));
    int randomNum = 0;
    int userNum = 0;
    int guessedNumCount = 0;
    while (randomNum == 0) {
        randomNum = rand() % maxnum+1;
    }

    while (userNum != randomNum) {
        cout << "Guess a randomly generated number: ";
        cin >> userNum;
        ++guessedNumCount;
        // cout << guessedNumCount;

        if (userNum > randomNum) {
            cout << "Guessed number is higher than random number!" << endl;
        } else if (userNum < randomNum) {
            cout << "Guessed number is lower than random number!" << endl;
        } else {
            break;
        }
    }

    return guessedNumCount;
}


int main()
{
    int maxnum = 0;
    cout << "Give a maxinum number for randomizer: ";
    cin >> maxnum;

    int guesses = game(maxnum);

    cout << "You guessed the correct number. Tries used: " << guesses << endl;

    return 0;
}

