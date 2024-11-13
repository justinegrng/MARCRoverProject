#include <stdio.h>
#include "map.h"
#include "tree.h"

int main() {
    t_map map;
// The following preprocessor directive checks if the code is being compiled on a Windows system.
// If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
// On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

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

    // Utilisation des fonctions de l'arbre
    Node* root = createNode(1);
    root->left = createNode(2);
    root->middle = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->middle = createNode(6);
    root->left->right = createNode(7);

    // Trouver la feuille minimum
    int minLeaf = findMinLeaf(root);
    printf("Minimum leaf value: %d\n", minLeaf);

    //Trouver le chemin vers la feuille minimum
    int path[100];
    int pathLen = findPathToMinLeaf(root, path, 0);
    printf("Path to minimum leaf: ");
    for (int i = 0; i < pathLen; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    freeTree(root);

    return 0;
}