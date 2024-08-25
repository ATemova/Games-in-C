#include <stdio.h>

#define ROWS 6
#define COLS 7

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int dropPiece(char board[ROWS][COLS], int col, char piece) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == ' ') {
            board[row][col] = piece;
            return row;
        }
    }
    return -1;
}

int checkWin(char board[ROWS][COLS], char piece) {
    // Check horizontal, vertical, and diagonal lines
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == piece) {
                if (c + 3 < COLS && board[r][c + 1] == piece && board[r][c + 2] == piece && board[r][c + 3] == piece) return 1;
                if (r + 3 < ROWS && board[r + 1][c] == piece && board[r + 2][c] == piece && board[r + 3][c] == piece) return 1;
                if (r + 3 < ROWS && c + 3 < COLS && board[r + 1][c + 1] == piece && board[r + 2][c + 2] == piece && board[r + 3][c + 3] == piece) return 1;
                if (r - 3 >= 0 && c + 3 < COLS && board[r - 1][c + 1] == piece && board[r - 2][c + 2] == piece && board[r - 3][c + 3] == piece) return 1;
            }
        }
    }
    return 0;
}

int main() {
    char board[ROWS][COLS];
    int col;
    char player = 'X';

    // Initialize the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    while (1) {
        printBoard(board);
        printf("Player %c, enter column (0-6): ", player);
        scanf("%d", &col);

        if (col < 0 || col >= COLS) {
            printf("Invalid column. Try again.\n");
            continue;
        }

        int row = dropPiece(board, col, player);
        if (row == -1) {
            printf("Column full. Try again.\n");
            continue;
        }

        if (checkWin(board, player)) {
            printBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
