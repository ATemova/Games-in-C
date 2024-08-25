#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4  // Grid size (4x4)
#define NUM_PAIRS (SIZE * SIZE / 2)

void shuffle(int grid[SIZE][SIZE]) {
    int numbers[NUM_PAIRS * 2];
    for (int i = 0; i < NUM_PAIRS; i++) {
        numbers[i] = numbers[i + NUM_PAIRS] = i + 1;
    }

    // Shuffle numbers
    for (int i = NUM_PAIRS * 2 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = numbers[i * SIZE + j];
        }
    }
}

void printGrid(int grid[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%2d ", grid[i][j]);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};
    int x1, y1, x2, y2;
    int matches = 0;
    int turns = 0;

    srand(time(0));
    shuffle(grid);

    while (matches < NUM_PAIRS) {
        printGrid(grid, revealed);

        printf("Enter coordinates of the first card (row col): ");
        scanf("%d %d", &x1, &y1);
        x1--; y1--;

        printf("Enter coordinates of the second card (row col): ");
        scanf("%d %d", &x2, &y2);
        x2--; y2--;

        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE ||
            x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE ||
            (x1 == x2 && y1 == y2) ||
            revealed[x1][y1] || revealed[x2][y2]) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        revealed[x1][y1] = 1;
        revealed[x2][y2] = 1;
        printGrid(grid, revealed);

        if (grid[x1][y1] == grid[x2][y2]) {
            printf("It's a match!\n");
            matches++;
        } else {
            printf("No match. Try again.\n");
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
        
        turns++;
    }

    printf("Congratulations! You've matched all pairs in %d turns.\n", turns);

    return 0;
}
