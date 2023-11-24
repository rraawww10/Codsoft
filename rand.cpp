#include <iostream>
#include <cstdlib>
#include <ctime>


void clearInputBuffer() {
    while (std::cin.get() != '\n') {
        
    }
}

int main() {
    using namespace std; 
    
    srand(static_cast<unsigned>(time(nullptr)));

   
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Guess a number to match with the random number. If the guessed number is equal to the random number generated, You Win" << endl;

    for (;; ++attempts) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer(); 
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number (" << secretNumber << ") in " << attempts + 1 << " attempts." << endl;
            break; 
        }
    }

    return 0;
}
 