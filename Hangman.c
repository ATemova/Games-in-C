#include <stdio.h>
#include <string.h>

#define MAX_TRIES 6
#define WORD_SIZE 100

void printWordState(const char* word, const char* guesses) {
    for (int i = 0; i < strlen(word); i++) {
        if (strchr(guesses, word[i])) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char word[WORD_SIZE] = "programming";
    char guesses[WORD_SIZE] = "";
    char guess;
    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("Current word state: ");
        printWordState(word, guesses);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        if (strchr(guesses, guess)) {
            printf("You already guessed '%c'.\n", guess);
            continue;
        }

        strncat(guesses, &guess, 1);

        if (!strchr(word, guess)) {
            tries++;
            printf("Wrong guess! You have %d tries left.\n", MAX_TRIES - tries);
        }

        if (strspn(word, guesses) == strlen(word)) {
            printf("Congratulations! You've guessed the word: %s\n", word);
            break;
        }
    }

    if (tries == MAX_TRIES) {
        printf("Game Over! The word was: %s\n", word);
    }

    return 0;
}
