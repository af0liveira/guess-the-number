#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("  _____                    _   _          _____           _            \n");
    printf(" |   __|_ _ ___ ___ ___   | |_| |_ ___   |   | |_ _ _____| |_ ___ ___  \n");
    printf(" |  |  | | | -_|_ -|_ -|  |  _|   | -_|  | | | | | |     | . | -_|  _| \n");
    printf(" |_____|___|___|___|___|  |_| |_|_|___|  |_|___|___|_|_|_|___|___|_|   \n");

    int t = time(0);  // number of seconds since the epoch
    srand(t);         // seed the random number generator
    int secret_number = rand() % 100;  // get a random number in [0, 99]

    int game_level;

    printf("\nWelcome to the game!\n");
    printf("What difficulty level would you like?\n");
    printf("(1) Easy, (2) Medium, or (3) Hard? ");
    scanf("%d", &game_level);

    int player_won = 0;
    int guessed_number;
    int num_attempts = 0;
    float score = 1000;

    int attempt_limit;

    switch(game_level) {
        case 1:
            attempt_limit = 20;
            break;

        case 2:
            attempt_limit = 15;
            break;

        case 3:
            attempt_limit = 6;
            break;

        default:
            attempt_limit = 6;
            break;
    }

    printf("\nOK! You start with %.0f points.\n", score);
    printf("And you have %d guesses.\n", attempt_limit);

    for (int i = 1; i <= attempt_limit; i++) {

        printf("\nWhat is the secret number? ");
        scanf("%d", &guessed_number);

        // validate user's input

        int invalid_guess = guessed_number < 0 || guessed_number > 99;

        if (invalid_guess) {
            printf("You must choose a number from 0 to 99! Please pick again.\n");
            attempt_limit++;  // compensate for invalid guesses
            continue;
        }
        
        // evaluate the player's guess

        player_won = (guessed_number == secret_number);

        if (player_won) {
            break;
        } 
        else {

            // Update score
            score -= abs(secret_number - guessed_number) / 2.0;

            int overestimated_guess = guessed_number > secret_number;

            if (overestimated_guess) {
                printf("Nope! Perhaps you should try a smaller number...\n");
            } else {
                printf("Nope! Maybe you should try a larger number...\n");
            }

        }

        num_attempts++;
    }

    if (player_won) {
        printf("\n");
        printf("YOU WON! CONGRATULATIONS!\n");
        printf("You guessed the number in %d attempts.\n", num_attempts);
        printf("Your final score: %.1f points\n\n", score);
    }
    else {
        printf("\nGAME OVER!\n");
        printf("You lost. Maybe you'll win next time?...\n\n");
    }

    return 0;

}