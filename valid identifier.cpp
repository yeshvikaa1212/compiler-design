#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(const char *str) {
    // Check if the first character is a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0; // Not a valid identifier
    }

    // Check the remaining characters
    for (int i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0; // Not a valid identifier
        }
    }

    return 1; // Valid identifier
}

int main() {
    char identifier[50];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("%s is a valid identifier.\n", identifier);
    } else {
        printf("%s is not a valid identifier.\n", identifier);
    }

    return 0;
}
