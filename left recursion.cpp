#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

int n;
char productions[MAX_PRODUCTIONS][MAX_SYMBOLS];
char new_productions[MAX_PRODUCTIONS][MAX_SYMBOLS];
int num_new_productions;

void eliminate_left_recursion() {
    num_new_productions = 0;

    for (int i = 0; i < n; i++) {
        char non_terminal = productions[i][0];
        int num_current_productions = 0;

        for (int j = 2; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == '|') {
                num_current_productions++;
                new_productions[num_new_productions][0] = non_terminal;
                new_productions[num_new_productions][1] = '\'';
                for (int k = j + 1, l = 2; productions[i][k] != '\0'; k++, l++) {
                    new_productions[num_new_productions][l] = productions[i][k];
                }
                new_productions[num_new_productions][strlen(new_productions[num_new_productions])] = non_terminal;
                new_productions[num_new_productions][strlen(new_productions[num_new_productions])] = '\'';
                new_productions[num_new_productions][strlen(new_productions[num_new_productions])] = '\0';
                num_new_productions++;
            }
        }
        new_productions[num_new_productions][0] = non_terminal;
        new_productions[num_new_productions][1] = '\'';
        new_productions[num_new_productions][2] = '\0';
        num_new_productions++;

        int k = 0;
        for (int j = 2; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == '|') {
                productions[i][j] = '\0';
                k = j + 1;
            }
        }
        productions[i][k++] = non_terminal;
        productions[i][k++] = '\'';
        productions[i][k++] = '|';
        productions[i][k++] = '\0';
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    eliminate_left_recursion();

    printf("Productions after eliminating left recursion:\n");
    for (int i = 0; i < num_new_productions; i++) {
        printf("%s\n", new_productions[i]);
    }

    return 0;
}

