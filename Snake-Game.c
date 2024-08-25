#include <stdio.h>
#include <conio.h> // For _getch()

#define WIDTH 20
#define HEIGHT 10

void printBoard(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[HEIGHT][WIDTH];
    int snakeX = WIDTH / 2, snakeY = HEIGHT / 2;
    int foodX = rand() % WIDTH, foodY = rand() % HEIGHT;
    char input;

    // Initialize board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    board[snakeY][snakeX] = '*';
    board[foodY][foodX] = '#';

    while (1) {
        printBoard(board);

        input = _getch(); // Get user input

        switch (input) {
            case 'w': snakeY--; break;
            case 's': snakeY++; break;
            case 'a': snakeX--; break;
            case 'd': snakeX++; break;
        }

        // Check for collision with walls or food here

        board[snakeY][snakeX] = '*';
        board[foodY][foodX] = '#';
    }

    return 0;
}
