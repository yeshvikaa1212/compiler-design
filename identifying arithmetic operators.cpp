#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return true;
    else
        return false;
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

    return 0;
}

