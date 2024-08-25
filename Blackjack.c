#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 5

int drawCard() {
    return rand() % 11 + 1; // Card values between 1 and 11
}

int main() {
    int playerTotal = 0, dealerTotal = 0;
    int playerCard, dealerCard;

    srand(time(0));

    // Draw initial cards for player and dealer
    playerCard = drawCard();
    playerTotal += playerCard;
    printf("Player draws a card: %d\n", playerCard);

    dealerCard = drawCard();
    dealerTotal += dealerCard;
    printf("Dealer draws a card: %d\n", dealerCard);

    // Player's turn
    char choice;
    while (playerTotal < 21) {
        printf("Player total: %d. Draw another card? (y/n): ", playerTotal);
        scanf(" %c", &choice);

        if (choice == 'y') {
            playerCard = drawCard();
            playerTotal += playerCard;
            printf("Player draws a card: %d\n", playerCard);
        } else {
            break;
        }
    }

    // Dealer's turn
    while (dealerTotal < 17) {
        dealerCard = drawCard();
        dealerTotal += dealerCard;
        printf("Dealer draws a card: %d\n", dealerCard);
    }

    // Determine winner
    printf("Player total: %d, Dealer total: %d\n", playerTotal, dealerTotal);

    if (playerTotal > 21) {
        printf("Player busts! Dealer wins.\n");
    } else if (dealerTotal > 21) {
        printf("Dealer busts! Player wins.\n");
    } else if (playerTotal > dealerTotal) {
        printf("Player wins!\n");
    } else if (dealerTotal > playerTotal) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
