#include <stdio.h>

int recherche_sequentielle(int liste[], int taille, int element_recherche) {
    int index = 0;  // initialisation de l'index

    // boucle "Tant que" jusqu'à trouver l'élément ou atteindre la fin de la liste
    while (index < taille) {
        if (liste[index] == element_recherche) {
            return index;  // l'élément est trouvé, retourner l'index
        }
        index++;  // passer à l'élément suivant
    }
    
    return -1;  // si l'élément n'est pas trouvé, retourner -1
}

int main() {
    int liste[] = {3, 5, 2, 9, 1, 4};
    int taille = sizeof(liste) / sizeof(liste[0]);
    int element_recherche = 9;
    int resultat = recherche_sequentielle(liste, taille, element_recherche);

    if (resultat != -1) {
        printf("L'élément %d a été trouvé à l'index %d.\n", element_recherche, resultat);
    } else {
        printf("L'élément %d n'a pas été trouvé dans la liste.\n", element_recherche);
    }

    return 0;
}