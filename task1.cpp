#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessingGame {
private:
    int randomNumber;
    int attempts;
    bool isGameOver;

public:
    NumberGuessingGame() {
        srand(time(nullptr)); // Seed random number generator
        randomNumber = rand() % 100 + 1; // Generate random number between 1 and 100
        attempts = 0;
        isGameOver = false;
    }

    void playGame() {
        cout << "Welcome to the Number Guessing Game!\n";
        cout << "I have selected a random number between 1 and 100. Try to guess it!\n";

        while (!isGameOver) {
            int guess = getGuessFromPlayer();
            processGuess(guess);
        }
    }

private:
    int getGuessFromPlayer() {
        int guess;
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;
        return guess;
    }

    void processGuess(int guess) {
        attempts++;

        if (guess < 1 || guess > 100) {
            cout << "Invalid guess! Please enter a number between 1 and 100.\n";
        } else if (guess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
            isGameOver = true;
        }
    }
};

int main() {
    NumberGuessingGame game;
    game.playGame();
    return 0;
}

