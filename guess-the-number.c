#include <stdio.h>
#include <stdlib.h>

int main() {

    // print the game's header
    printf("********************************\n");
    printf("* Welcome to Guess the Number! *\n");
    printf("********************************\n");

    // define the secret number
    int secret_number = 42;  // TODO: make in a random integer

    int user_guess;
    int num_attempts = 0;
    float score = 1000;

    while (1) {

        printf("Current score: %.1f\n", score);

        // ask the user to guess the number

        printf("What is the secret number? ");
        scanf("%d", &user_guess);

        // validate user's input

        int invalid_guess = user_guess < 0;

        if (invalid_guess) {
            printf("You can't pick negative numbers! Let's try again.\n");
            continue;
        } else {
            num_attempts++;
        }
        
        // evaluate the player's guess

        int good_guess = (user_guess == secret_number);

        if (good_guess) {
            printf("Congratulations! The secret number was indeed %d!\n", secret_number);
            printf("** Final score: %.1f **\n", score);
            break;
        } else {

            // Update score
            score -= abs(secret_number - user_guess) / 2.0;

            // Give hint for player's next guess

            int overestimated_guess = user_guess > secret_number;

            if (overestimated_guess) {
                printf("Nope! %d is larger than the secret number!\n", user_guess);
            } else {
                printf("Nope! %d is lower than the secret number!\n", user_guess);
            }

        }

    }

    return 0;

}