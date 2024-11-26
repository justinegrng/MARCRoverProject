//
// Created by jugar on 22/11/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "loc.h"
#include "moves.h"

// Function to display the menu
void printMenu() {
    printf("1. Afficher l'arbre\n");
    printf("2. Afficher la feuille minimum\n");
    printf("3. Afficher le chemin vers la feuille minimum\n");
    printf("4. Sortir\n");
}

// Function to handle the user's choice
void interactiveMenu() {
    int choice;
    printMenu();
    printf("Entrez votre choix: ");
    int result = scanf("%d", &choice);

    if (result != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    switch (choice) {
        case 1:
            printf("Afficher l'arbre sélectionné.\n");
            // Code pour afficher l'arbre ici
            interactiveMenu();
            return;
        case 2:
            printf("Afficher la feuille minimum sélectionnée.\n");
            // FOnction
            interactiveMenu();
            return;
        case 3:
            printf("Afficher le chemin vers la feuille minimum sélectionné.\n");
            // Fonction
            interactiveMenu();
            return;
        case 4:
            printf("Sortir sélectionné.\n");
            exit(0);
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            interactiveMenu();
            return;
    }
}