#include <stdio.h>

int recherche_dichotomique(int liste[], int taille, int element) {
    int gauche = 0;
    int droite = taille - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;
        int valeur_milieu = liste[milieu];

        if (valeur_milieu == element) {
            return milieu;
        } else if (valeur_milieu < element) {
            gauche = milieu + 1;
        } else {
            droite = milieu - 1;
        }
    }

    return -1;
}

int main() {
    int liste_triee[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int taille = sizeof(liste_triee) / sizeof(liste_triee[0]);
    int element_a_trouver = 7;

    int index = recherche_dichotomique(liste_triee, taille, element_a_trouver);
    if (index != -1) {
        printf("Élément trouvé à l'index %d.\n", index);
    } else {
        printf("Élément non trouvé.\n");
    }

    return 0;
}