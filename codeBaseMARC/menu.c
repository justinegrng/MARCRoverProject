//
// Created by jugar on 22/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "loc.h"
#include "moves.h"
#include "tree.h"
#include "map.h"

void printMenu() {
    printf("1. Afficher la carte\n");
    printf("2. Afficher la carte avec le Rover en (0,0)\n");
    printf("3. Construire un arbre N-aire\n");
    printf("4. \n");
    printf("5. \n");
    printf("6. \n");
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
        t_map map;

#if defined(_WIN32) || defined(_WIN64)
        map = createMapFromFile("..\\maps\\example1.map");
#else
        map = createMapFromFile("../maps/example1.map");
#endif
        t_localisation loc = loc_init(0, 0, NORTH);
        Node* root = createNode(loc, map.soils[loc.pos.y][loc.pos.x]);
        buildTree(root, map, 0);
        int min_value = INT_MAX;
        Node* optimal_leaf = NULL;
        t_move sequence[5];
        int length;
        switch (choice) {
            case 1:
                printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
                for (int i = 0; i < map.y_max; i++) {
                    for (int j = 0; j < map.x_max; j++) {
                        printf("%d ", map.soils[i][j]);
                    }
                    printf("\n");
                }
                for (int i = 0; i < map.y_max; i++) {
                    for (int j = 0; j < map.x_max; j++) {
                        printf("%-5d ", map.costs[i][j]);
                    }
                    printf("\n");
                }
                displayMap(map);
                interactiveMenu();
                return;
            case 2:
                printf("\n");
                displayMapWithRover(map, loc_init(0, 0, NORTH));
                interactiveMenu();
                return;
            case 3:
                findOptimalPath(root, &min_value, &optimal_leaf);
                printf("Minimum value: %d\n", min_value);
                getOptimalSequence(optimal_leaf, sequence, &length);
                printf("Optimal leaf: %d %d\n", optimal_leaf->loc.pos.x, optimal_leaf->loc.pos.y);

                printf("Chemin optimal: ");
                for (int i = 0; i < length; i++) {
                    printf("%d ", sequence[i]);
                }
                printf("\n");

                applyOptimalSequence(&loc, sequence, length);
                displayMapWithRover(map, loc);
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
                printf("Sortie.\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                interactiveMenu();
                return;
        }
    }
}
