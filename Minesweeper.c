#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MINES 5

void initializeBoard(char board[SIZE][SIZE], int mines[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
            mines[i][j] = 0;
        }
    }

    int placedMines = 0;
    while (placedMines < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (mines[x][y] == 0) {
            mines[x][y] = 1;
            placedMines++;
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int countMines(int x, int y, int mines[SIZE][SIZE]) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
                count += mines[i][j];
            }
        }
    }
    return count;
}

int main() {
    char board[SIZE][SIZE];
    int mines[SIZE][SIZE];
    int x, y;

    srand(time(0));
    initializeBoard(board, mines);

    while (1) {
        printBoard(board);
        printf("Enter coordinates (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid coordinates.\n");
            continue;
        }

        if (mines[x][y] == 1) {
            printf("Boom! Game Over.\n");
            break;
        }

        int mineCount = countMines(x, y, mines);
        board[x][y] = mineCount + '0';

        if (mineCount == 0) {
            board[x][y] = ' ';
        }
    }

    return 0;
}
