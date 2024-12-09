#include <stdio.h>

int main() {
    int i, j;
    char matrix[5][5] = {
        {'1', '2', '3', '4', '5'},
        {'7', 'a', 'c', 'd', 'e'},
        {'6', '9', '2', '8', '3'},
        {'5', '6', 'p', 'n', '3'},
        {'2', '9', 't', 'm', 'k'}
    };

    // ����� �������� �������
    printf("Full matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n"); 
    }

    // ����� ������ ��� ������� �������
    printf("\nRows with even indices:\n");
    for (i = 0; i < 5; i += 2) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // ����� ������� ��� ������� ������� �� �� ��
    printf("\nOdd-indexed elements in each row:\n");
    for (i = 0; i < 5; i++) {
        for (j = 1; j < 5; j += 2) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // ����� ������� ��� ����� �������
    printf("La diagonale: \n");
    for (i = 0; i < 5; i++) {
        printf("%c ", matrix[i][i]);
    }
    printf("\n");

    // ����� ������� ��� ����� �������
    printf("La diagonale inverse: \n");
    for (i = 0; i < 5; i++) {
        printf("%c ", matrix[i][4-i]);
    }
    printf("\n");

    return 0;
}

