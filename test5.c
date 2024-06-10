#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialisation des variables
    int nombreMystere, nombreEntre, tentatives;
    char continuer = 'o';

    // Boucle principale du jeu
    while (continuer == 'o' || continuer == 'O') {
        // Saisie du nombre mystère par l'administrateur
        printf("Administrateur, entrez le nombre mystère (entre 1 et 100) : ");
        scanf("%d", &nombreMystere);

        // Validation du nombre mystère
        while (nombreMystere < 1 || nombreMystere > 100) {
            printf("Veuillez entrer un nombre valide entre 1 et 100 : ");
            scanf("%d", &nombreMystere);
        }

        tentatives = 0;

        printf("Bienvenue au jeu du Juste Prix !\n");
        printf("Devinez le nombre mystère (entre 1 et 100) :\n");

        // Boucle de devinette
        do {
            // Saisie du nombre par l'utilisateur
            printf("Entrez un nombre : ");
            scanf("%d", &nombreEntre);
            tentatives++;

            // Vérification du nombre entré
            if (nombreEntre < nombreMystere) {
                printf("C'est plus !\n");
            } else if (nombreEntre > nombreMystere) {
                printf("C'est moins !\n");
            } else {
                printf("Bravo, vous avez trouvé le nombre mystère en %d tentatives !\n", tentatives);
            }
        } while (nombreEntre != nombreMystere);

        // Demander si l'utilisateur veut rejouer
        printf("Voulez-vous rejouer ? (o/n) : ");
        scanf(" %c", &continuer);
    }

    printf("Merci d'avoir joué ! À bientôt.\n");

    return 0;
}