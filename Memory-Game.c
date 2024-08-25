#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    char hiddenBoard[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};
    int x1, y1, x2, y2;
    int pairs = 0;

    // Initialize hidden board with pairs
    char values[SIZE * SIZE / 2];
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        values[i] = 'A' + i;
    }
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        while (hiddenBoard[x][y] != 0) {
            x = rand() % SIZE;
            y = rand() % SIZE;
        }
        hiddenBoard[x][y] = values[i];
        hiddenBoard[(x + 1) % SIZE][(y + 1) % SIZE] = values[i];
    }

    while (pairs < SIZE * SIZE / 2) {
        printBoard(board);
        printf("Enter coordinates for first card (x y): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter coordinates for second card (x y): ");
        scanf("%d %d", &x2, &y2);

        if (hiddenBoard[x1][y1] == hiddenBoard[x2][y2]) {
            board[x1][y1] = hiddenBoard[x1][y1];
            board[x2][y2] = hiddenBoard[x2][y2];
            pairs++;
        } else {
            printf("No match! Try again.\n");
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
    }

    printBoard(board);
    printf("Congratulations! You've matched all pairs.\n");

    return 0;
}
