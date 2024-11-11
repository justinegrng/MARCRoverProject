//
// Created by jugar on 11/11/2024.
//

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Créer un nouveau noeud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->middle = NULL;
    return newNode;
}

//Libérer la mémoire allouée pour l'arbre
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    freeTree(root->middle);
    free(root);
}

//Trouver la feuille minimum
int findMinLeaf(Node* root) {
    if (root == NULL) return INT_MAX;
    if (root->left == NULL && root->middle == NULL && root->right == NULL) return root->value;

    int leftMin = findMinLeaf(root->left);
    int middleMin = findMinLeaf(root->middle);
    int rightMin = findMinLeaf(root->right);

    return (leftMin < middleMin) ? ((leftMin < rightMin) ? leftMin : rightMin) : ((middleMin < rightMin) ? middleMin : rightMin);
}


//Trouver le chemin vers la feuille minimum
int findPathToMinLeaf(Node* root, int* path, int pathLen) {
    if (root == NULL) return 0;
    path[pathLen] = root->value;
    pathLen++;

    if (root->left == NULL && root->middle == NULL && root->right == NULL) return pathLen;

    int leftPathLen = findPathToMinLeaf(root->left, path, pathLen);
    int middlePathLen = findPathToMinLeaf(root->middle, path, pathLen);
    int rightPathLen = findPathToMinLeaf(root->right, path, pathLen);

    int minPathLen = (leftPathLen < middlePathLen) ? ((leftPathLen < rightPathLen) ? leftPathLen : rightPathLen) : ((middlePathLen < rightPathLen) ? middlePathLen : rightPathLen);
    return minPathLen;
}