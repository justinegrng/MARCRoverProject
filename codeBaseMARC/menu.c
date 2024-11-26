//
// Created by jugar on 22/11/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "loc.h"
#include "moves.h"
#include "tree.h"

// Function to display the menu
void printMenu() {
    printf("1. Arbre avec 3 choix parmi 4 ou 5 valeurs possibles\n");
    printf("2. Afficher la feuille minimum\n");
    printf("3. Afficher le chemin vers la feuille minimum\n");
    printf("4. Sortir\n");
    printf("\n");
}

// Function to handle the user's choice
void interactiveMenu() {
    int choice;
    printMenu();
    printf("Entrez votre choix: \n");
    printf("\n");
    int result = scanf("%d", &choice);

    if (result != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    switch (choice) {
        case 1:
            printf("\n");
            TreeNode* root = createNode(0);
            buildSimpleTree(root);

            int minLeaf = findMinLeaf(root);
            printf("Valeur de la feuille minimum: %d\n", minLeaf);
            printf("Chemin vers la feuille minimum: ");
            printPathToMinLeaf(root, minLeaf);
            printf("\n");
            freeTree(root);
            printf("\n");
            interactiveMenu();
            return;
        case 2:
            printf("\n");
            // FOnction
            interactiveMenu();
            return;
        case 3:
            printf("\n");
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