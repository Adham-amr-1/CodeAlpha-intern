#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Randoming number 
    srand(time(NULL));

    // Generate a Random number between 1 and 100
    int randonum = rand() % 100 + 1;

    int guess;
    int tries = 0;
again:
    cout << "***********************************************\n";
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the number between 1 and 100." << endl;
    cout << "***********************************************\n";
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess == randonum) {
            cout << "Congratulations! You guessed the correct number in " << tries << " Tries." << endl;
        }
        else if (guess < randonum) {
            cout << "Too low. Try again." << endl;
        }
        else {
            cout << "Too high. Try again." << endl;
        }

    } while (guess != randonum);
    char asker;
    cout << "Do You want to try again ? ( Y / N )" << endl;
    cin >> asker;
    if (asker == 'Y' || asker == 'y') {
        tries = 0;
        randonum = rand() % 100 + 1;
        goto again;
    }
    else {
        cout << endl << "GoodBye <3" << endl;
    }
    return 0;
}
