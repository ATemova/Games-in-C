#include <stdio.h>

#define SIZE 5
#define SHIP_COUNT 3

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
    int ships[SHIP_COUNT][2] = {{1, 1}, {2, 3}, {4, 2}};
    int x, y, hits = 0;

    // Initialize board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }

    while (hits < SHIP_COUNT) {
        printBoard(board);
        printf("Enter coordinates (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid coordinates.\n");
            continue;
        }

        int hit = 0;
        for (int i = 0; i < SHIP_COUNT; i++) {
            if (ships[i][0] == x && ships[i][1] == y) {
                board[x][y] = 'X';
                hit = 1;
                hits++;
                break;
            }
        }

        if (!hit) {
            board[x][y] = 'O';
        }

        if (hits == SHIP_COUNT) {
            printf("Congratulations! All ships sunk.\n");
        }
    }

    return 0;
}
