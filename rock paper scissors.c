#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, computerChoice;
    const char *choices[] = {"Rock", "Paper", "Scissors"};
    srand(time(0));

    printf("Enter 1 for Rock, 2 for Paper, 3 for Scissors: ");
    scanf("%d", &userChoice);
    computerChoice = rand() % 3 + 1;

    printf("Computer chose: %s\n", choices[computerChoice - 1]);

    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}
