#include <stdio.h>

int main() {

    // print the game's header
    printf("********************************\n");
    printf("* Welcome to Guess the Number! *\n");
    printf("********************************\n");

    // define the secret number
    int secretnum = 42;  // TODO: make in a random integer

    // ask the user to guess the number
    int trialnum;
    printf("What is the secret number? \n");
    scanf("%d", &trialnum);
    
    printf("The answer is %d. Your guess was %d.\n", secretnum, trialnum);

    return 0;

}