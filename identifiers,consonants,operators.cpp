#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

bool isIdentifierChar(char ch) {
    return isalpha(ch) || ch == '_';
}

bool isConstantChar(char ch) {
    return isdigit(ch);
}

int main() {
    char input[100];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    printf("Identified operators: ");
    for (int i = 0; input[i] != '\0'; i++) {
        if (isOperator(input[i])) {
            printf("%c ", input[i]);
        }
    }
    printf("\n");

    printf("Identified identifiers: ");
    for (int i = 0; input[i] != '\0'; i++) {
        if (isIdentifierChar(input[i])) {
            while (isIdentifierChar(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf(" ");
        }
    }
    printf("\n");

    printf("Identified constants: ");
    for (int i = 0; input[i] != '\0'; i++) {
        if (isConstantChar(input[i])) {
            while (isConstantChar(input[i])) {
                printf("%c", input[i]);
                i++;
            }
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

