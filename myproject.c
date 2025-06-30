// #include "include/input_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));

    int endGuess, guess, attempts = 0; 

    //generating a random number
    int randomNumber = (rand() % 50) + 1;

    // printf("Random Number: %d\n", randomNumber);

    while (endGuess == 0){
        // output of guess number
        printf("Guess the Number (1 to 50): ");
        scanf("%d", &guess); // &guess passes the address of 'guess'
        attempts = attempts + 1;
        if (randomNumber > guess){
            printf("Too low! Try again! \n");
        }else if (randomNumber < guess){
            printf("Too High! Try again! \n");
        }else{
            if (attempts > 1){
                printf("Correct! You guessed it in %d attempts.\n", attempts);
            }else{
                printf("Correct! You guessed it in %d attempt.\n", attempts);
            }
            endGuess = 1;
        }
    }

    


    return 0;



}



