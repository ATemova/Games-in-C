#include <stdio.h>

int main() {
    int choice;

    printf("You are in a forest. There are two paths ahead of you.\n");
    printf("1. Take the left path\n");
    printf("2. Take the right path\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You encounter a friendly deer and enjoy a pleasant walk.\n");
            break;
        case 2:
            printf("You find a hidden treasure chest! Congratulations!\n");
            break;
        default:
            printf("Invalid choice. You decide to stay put.\n");
            break;
    }

    return 0;
}
