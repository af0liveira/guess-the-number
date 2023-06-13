#include <stdio.h>

#define NUM_GUESSES 3   // maximum number of guesses per game

int main() {

    // print the game's header
    printf("********************************\n");
    printf("* Welcome to Guess the Number! *\n");
    printf("********************************\n");

    // define the secret number
    int secret_number = 42;  // TODO: make in a random integer

    for (int i = 1; i <= NUM_GUESSES; i++) {

        // ask the user to guess the number
        int user_guess;
        printf("What is the secret number? \n");
        scanf("%d", &user_guess);

        // evaluate the player's guess
        int good_guess = (user_guess == secret_number);
        
        if (good_guess) {
            printf("Congratulations! The secret number was indeed %d!\n", secret_number);
            break;
        } else {
            int guess_is_larger = user_guess > secret_number;

            if (guess_is_larger) {
                printf("Nope! %d is larger than the secret number!\n", user_guess);
            } else {
                printf("Nope! %d is lower than the secret number!\n", user_guess);
            }

            printf("Try again! ");

        }

    }

    return 0;

}