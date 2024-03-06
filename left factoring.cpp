#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 10

int n;
char productions[MAX_PRODUCTIONS][MAX_SYMBOLS];
char new_productions[MAX_PRODUCTIONS][MAX_SYMBOLS];
int num_new_productions;

void left_factoring() {
    num_new_productions = 0;

    for (int i = 0; i < n; i++) {
        int common_length = 0;
        char common_prefix[MAX_SYMBOLS];
        int num_alternatives = 0;

        // Find common prefix and count number of alternatives
        for (int j = 5; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == '|' || productions[i][j] == '\0') {
                num_alternatives++;
                break;
            }
            common_prefix[common_length++] = productions[i][j];
        }
        common_prefix[common_length] = '\0';

        // If common prefix found, create new production and modify original production
        if (num_alternatives > 1) {
            new_productions[num_new_productions][0] = productions[i][0];
            new_productions[num_new_productions][1] = '\'';
            new_productions[num_new_productions][2] = '\0';
            num_new_productions++;

            for (int j = 0; j < num_alternatives; j++) {
                if (j == 0) {
                    strcpy(productions[i], "");
                    strcat(productions[i], common_prefix);
                    strcat(productions[i], productions[num_new_productions - 1]);
                } else {
                    strcpy(new_productions[num_new_productions], "");
                    strcat(new_productions[num_new_productions], common_prefix);
                    strcat(new_productions[num_new_productions], productions[i] + 4 + common_length);
                    num_new_productions++;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    left_factoring();

    printf("Productions after left factoring:\n");
    for (int i = 0; i < num_new_productions; i++) {
        printf("%s\n", new_productions[i]);
    }

    return 0;
}

