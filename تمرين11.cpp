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

    // ÿ»«⁄… «·„’›Ê›… »«·ﬂ«„·
    printf("Full matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n"); 
    }

    // ÿ»«⁄… «·’›Ê› –«  «·›Â«—” «·“ÊÃÌ…
    printf("\nRows with even indices:\n");
    for (i = 0; i < 5; i += 2) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // ÿ»«⁄… «·⁄‰«’— –«  «·›Â«—” «·›—œÌ… ›Ì ﬂ· ’›
    printf("\nOdd-indexed elements in each row:\n");
    for (i = 0; i < 5; i++) {
        for (j = 1; j < 5; j += 2) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // ÿ»«⁄… «·⁄‰«’— ⁄·Ï «·ﬁÿ— «·—∆Ì”Ì
    printf("La diagonale: \n");
    for (i = 0; i < 5; i++) {
        printf("%c ", matrix[i][i]);
    }
    printf("\n");

    // ÿ»«⁄… «·⁄‰«’— ⁄·Ï «·ﬁÿ— «·„⁄«ﬂ”
    printf("La diagonale inverse: \n");
    for (i = 0; i < 5; i++) {
        printf("%c ", matrix[i][4-i]);
    }
    printf("\n");

    return 0;
}

