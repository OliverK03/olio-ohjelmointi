#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
    int randomNum = 0;
    int userNum = 0;
    while (randomNum == 0) {
        randomNum = rand() % 21;
    }

    while (userNum != randomNum) {
        cout << "Guess a randomly generated number: ";
        cin >> userNum;

        if (userNum > randomNum) {
            cout << "Guessed number is higher than random number!" << endl;
        } else if (userNum < randomNum) {
            cout << "Guessed number is lower than random number!" << endl;
        } else {
            break;
        }
    }
    cout << "You guessed right!!" << endl;

    return 0;
}
