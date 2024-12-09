#include <stdio.h>
#include <stdlib.h>

char *ChargerChaine(int N) {
    char *chaine = (char*)malloc(N + 1);  //  Œ’Ì’ –«ﬂ—… ·⁄œœ N + 1 (·‹ '\0')
    if (chaine == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    printf("Enter the series: ");
    scanf("%s", chaine);  // ﬁ—«¡… «·”·”·… «·‰’Ì… »«” Œœ«„ scanf

    return chaine;
}

int Longueur(char *ch) {
    int len = 0;
    while (ch[len] != '\0') {
        len++;
    }
    return len;
}

void ChargerTab(char *p, char Tab[]) {
    int i = 0;
    while (p[i] != '\0') {
        Tab[i] = p[i];
        i++;
    }
    Tab[i] = '\0';  // «· √ﬂœ „‰ √‰ «·„’›Ê›…  ‰ ÂÌ »‹ '\0'
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

    // ﬁ—«¡… ÿÊ· «·”·”·… »«” Œœ«„ scanf
    printf("Enter the maximum length of the string: ");
    scanf("%d", &N);  // ﬁ—«¡… ÿÊ· «·”·”·…

    if (N <= 0) {
        printf("Please enter a positive number for N.\n");
        return 1;
    }

    // ﬁ—«¡… «·”·”·… «·‰’Ì…
    char *chaine = ChargerChaine(N);

    // Õ”«» ÿÊ· «·”·”·…
    int longueur = Longueur(chaine);

    //  Œ’Ì’ «·„’›Ê›… «· Ì ” Œ“‰ «·”·”·…
    char Tab[longueur + 1];  // «·„’›Ê›… · Œ“Ì‰ «·”·”·…
    ChargerTab(chaine, Tab);  // ‰”Œ «·”·”·… ≈·Ï «·„’›Ê›…

    // ⁄—÷ «·”·”·… «·√’·Ì…
    printf("Original series: ");
    AfficherTab(Tab, longueur);

    // ⁄ﬂ” «·”·”·…
    InverserTab(Tab, longueur);
    printf("Inverse series: ");
    AfficherTab(Tab, longueur);

    //  Õ—Ì— «·–«ﬂ—… «·„Œ’’…
    free(chaine);

    return 0;
}

