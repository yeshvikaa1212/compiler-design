#include <stdio.h>

int main() {
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0; // Flag to track whether we are inside a word

    printf("Enter text (Ctrl+D to end input):\n");

    while ((ch = getchar()) != EOF) {
        charCount++;

        // Check for newline character to count lines
        if (ch == '\n') {
            lineCount++;
        }

        // Check for space or newline to count words
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            wordCount++;
        }
    }

    printf("\nCharacter count: %d\nWord count: %d\nLine count: %d\n", charCount, wordCount, lineCount);

    return 0;
}

