//
// Created by jugar on 11/11/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "tree.h"

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->child1 = NULL;
    newNode->child2 = NULL;
    newNode->child3 = NULL;
    return newNode;
}

void addChild1(TreeNode* parent, int value) {
    parent->child1 = createNode(value);
}

void addChild2(TreeNode* parent, int value) {
    parent->child2 = createNode(value);
}

void addChild3(TreeNode* parent, int value) {
    parent->child3 = createNode(value);
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->child1);
    freeTree(root->child2);
    freeTree(root->child3);
    free(root);
}

void buildSimpleTree(TreeNode* root) {
    addChild1(root, 1);
    addChild2(root, 2);
    addChild3(root, 3);
    addChild1(root->child1, 4);
    addChild2(root->child1, 5);
    addChild3(root->child1, 6);
}


int findMinLeaf(TreeNode* root) {
    if (root == NULL) return INT_MAX;
    if (root->child1 == NULL && root->child2 == NULL && root->child3 == NULL) return root->value;
    int min1 = findMinLeaf(root->child1);
    int min2 = findMinLeaf(root->child2);
    int min3 = findMinLeaf(root->child3);
    return (min1 < min2 ? (min1 < min3 ? min1 : min3) : (min2 < min3 ? min2 : min3));
}

void printPathToMinLeaf(TreeNode* root, int minLeaf) {
    if (root == NULL) return;
    printf("%d ", root->value);
    if (root->value == minLeaf) return;
    if (root->child1 && findMinLeaf(root->child1) == minLeaf) {
        printPathToMinLeaf(root->child1, minLeaf);
    } else if (root->child2 && findMinLeaf(root->child2) == minLeaf) {
        printPathToMinLeaf(root->child2, minLeaf);
    } else if (root->child3) {
        printPathToMinLeaf(root->child3, minLeaf);
    }
}