#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val;
    struct element *suivant;
} element;

element *creerListe() {
    return NULL;
}

element *chargerListe(int Tab[], int n, element *liste) {
    for (int i = n - 1; i >= 0; i--) {
        element *nouveau = (element*)malloc(sizeof(element));
        nouveau->val = Tab[i];
        nouveau->suivant = liste;
        liste = nouveau;
    }
    return liste;
}

void afficherListe(element *liste) {
    while (liste != NULL) {
        printf("%d ", liste->val);
        liste = liste->suivant;
    }
    printf("\n");
}

// ÏÇáÉ áÍÐÝ ÇáÚäÕÑ ÇáÃÎíÑ ãä ÇáÞÇÆãÉ
element *supprimerEnFin(element *liste) {
    if (liste == NULL) {
        return NULL;
    }
    if (liste->suivant == NULL) {
        free(liste);
        return NULL;
    }
    element *tmp = liste;
    while (tmp->suivant->suivant != NULL) {
        tmp = tmp->suivant;
    }
    free(tmp->suivant);
    tmp->suivant = NULL;
    return liste;
}

element *ajouterEnDebut(element *liste, int valeur) {
    element *nouveau = (element*)malloc(sizeof(element));
    nouveau->val = valeur;
    nouveau->suivant = liste;
    return nouveau;
}

void viderListe(element *liste) {
    while (liste != NULL) {
        element *tmp = liste;
        liste = liste->suivant;
        free(tmp);
    }
}

int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element *liste = creerListe();
    liste = chargerListe(Tab, 10, liste);

    afficherListe(liste);

    element *L1 = supprimerEnFin(liste);
    afficherListe(L1);

    element *L2 = ajouterEnDebut(L1, 40);
    afficherListe(L2);

    viderListe(L2);

    return 0;
}
