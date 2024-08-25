#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

void addRandom(int board[SIZE][SIZE]) {
    int empty[SIZE * SIZE][2];
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                empty[count][0] = i;
                empty[count][1] = j;
                count++;
            }
        }
    }

    if (count == 0) return;

    int r = rand() % count;
    int x = empty[r][0];
    int y = empty[r][1];
    board[x][y] = (rand() % 2 + 1) * 2;
}

void mergeLeft(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int lastMerge = -1;
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j;
                while (k > 0 && board[i][k - 1] == 0) {
                    board[i][k - 1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
                if (k > 0 && board[i][k - 1] == board[i][k] && lastMerge != k - 1) {
                    board[i][k - 1] *= 2;
                    board[i][k] = 0;
                    lastMerge = k - 1;
                }
            }
        }
    }
}

int main() {
    int board[SIZE][SIZE] = {0};
    char move;
    int gameOver = 0;

    srand(time(0));
    addRandom(board);
    addRandom(board);

    while (!gameOver) {
        printBoard(board);
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'a':
                mergeLeft(board);
                addRandom(board);
                break;
            // Implement 'w', 's', 'd' similarly
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check for game over condition here
    }

    printf("Game Over!\n");

    return 0;
}
