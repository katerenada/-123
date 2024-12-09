#include <stdio.h>

int main() {
    // ����� ������ ������ ������� (������ �����)
    int Mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // ����� �������� �������
    printf("�������� �������:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", Mat[i][j]);
        }
        printf("\n");
    }

    // ����� �������
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int temp = Mat[i][j];
            Mat[i][j] = Mat[j][i];
            Mat[j][i] = temp;
        }
    }

    // ����� �������� ��� ����� �������
    printf("\n�������� ��� ����� �������:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", Mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
