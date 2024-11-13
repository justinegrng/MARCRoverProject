//
// Created by jugar on 11/11/2024.
//

#ifndef MARCROVER_TREE_H
#define MARCROVER_TREE_H

//Structure d'un noeud
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* middle;
} Node;

Node* createNode(int value);
void freeTree(Node* root);
int findMinLeaf(Node* root);
int findPathToMinLeaf(Node* root, int* path, int pathLen);

#endif // MARCROVER_TREE_H