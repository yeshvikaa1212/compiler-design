#include <stdio.h>

int main() {
  char expression[100];
  int i, precedence;

  printf("Enter an expression: ");
  scanf("%s", expression);

  // Calculate the precedence of each operator in the expression
  for (i = 0; expression[i] != '\0'; i++) {
    switch (expression[i]) {
      case '+':
      case '-':
        precedence = 1;
        break;
      case '*':
      case '/':
      case '%':
        precedence = 2;
        break;
      case '^':
        precedence = 3;
        break;
      default:
        precedence = 0;
        break;
    }

    // Print the precedence of the operator
    printf("%c: %d\n", expression[i], precedence);
  }

  return 0;
}
