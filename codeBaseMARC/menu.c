//
// Created by jugar on 22/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "loc.h"
#include "moves.h"
#include "tree.h"

void printMenu() {
    printf("1. Arbre avec 3 choix parmi 4 ou 5 valeurs possibles\n");
    printf("2. Afficher les temps de construction, de recherche d'un arbre avec 9 choix\n");
    printf("3. Afficher le chemin vers la feuille minimum\n");
    printf("4. Construire un arbre N-aire\n");
    printf("5. Imprimer l'arbre N-aire\n");
    printf("6. Trouver le chemin optimal\n");
    printf("7. Sortir\n");
    printf("\n");
}

void interactiveMenu() {
    int choice;

    while (1) {
        printMenu();
        printf("Entrez votre choix: \n");
        int result = scanf("%d", &choice);

        if (result != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                interactiveMenu();
                return;
            case 2:
                printf("\n");
                interactiveMenu();
                return;
            case 3:
                printf("\n");
                interactiveMenu();
                return;
            case 4:
                interactiveMenu();
                return;
            case 5:
                interactiveMenu();
                return;
            case 6:
                interactiveMenu();
                return;
            case 7:
                printf("Sortir sélectionné.\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }
}