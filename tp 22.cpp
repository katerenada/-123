#include <stdio.h>
#include <stdlib.h>

char *ChargerChaine(int N) {
    char *chaine = (char*)malloc(N + 1);  
    if (chaine == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    printf("Enter the series: ");
    scanf("%s", chaine);   

    return chaine;
}

int Longueur(char *ch) {
    int i = 0;
    while (ch[i] != '\0') {
        i++;
    }
    return i;
}

void ChargerTab(char *p, char Tab[]) {
    int i = 0;
    while (p[i] != '\0') {
        Tab[i] = p[i];
        i++;
    }
    Tab[i] = '\0';  // 
}

void InverserTab(char Tab[], int n) {
    char temp;
    for (int i = 0; i < n / 2; i++) {
        temp = Tab[i];
        Tab[i] = Tab[n - i - 1];
        Tab[n - i - 1] = temp;
    }
}

void AfficherTab(char Tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", Tab[i]);
    }
    printf("\n");
}

int main() {
    int N;
    printf("Enter the maximum length of the string: ");
    scanf("%d", &N);  

    if (N <= 0) {
        printf("Please enter a positive number for N.\n");
        return 1;
    }

    
    char *chaine = ChargerChaine(N);

    
    int longueur = Longueur(chaine);

    char Tab[longueur + 1];  
    ChargerTab(chaine, Tab);  

    printf("Original series: ");
    AfficherTab(Tab, longueur);

    InverserTab(Tab, longueur);
    printf("Inverse series: ");
    AfficherTab(Tab, longueur);

    free(chaine);

    return 0;
}

