//
// Created by jugar on 11/11/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "tree.h"
#include "loc.h"
#include "moves.h"
#include "map.h"

Node* createNode(t_localisation loc, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->loc = loc;
    newNode->value = value;
    newNode->child_count = 0;
    newNode->parent = NULL; // Initialize parent
    newNode->move = -1; // Initialize move
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->child_count < 9) {
        parent->children[parent->child_count++] = child;
        child->parent = parent; // Set parent
    }
}

void buildTree(Node* root, t_map map, int level) {
    if (level == 5 || isOutOfMap(map, root->loc) || isOnCrevasse(map, root->loc)) {
        return;
    }

    t_move moves[] = {T_LEFT, T_RIGHT, U_TURN, F_10, F_20, F_30, B_10};
    int num_moves = sizeof(moves) / sizeof(moves[0]);

    for (int i = 0; i < num_moves; i++) {
        t_localisation new_loc = move(root->loc, moves[i]);
        int value = map.soils[new_loc.pos.y][new_loc.pos.x];
        Node* child = createNode(new_loc, value);
        child->move = moves[i]; // Set move
        addChild(root, child);
        buildTree(child, map, level + 1);
    }
}

void findOptimalPath(Node* root, int* min_value, Node** optimal_leaf) {
    if (root->child_count == 0) {
        if (root->value < *min_value) {
            *min_value = root->value;
            *optimal_leaf = root;
        }
        return;
    }

    for (int i = 0; i < root->child_count; i++) {
        findOptimalPath(root->children[i], min_value, optimal_leaf);
    }
}

void getOptimalSequence(Node* leaf, t_move* sequence, int* length) {
    Node* current = leaf;
    *length = 0;

    while (current->parent != NULL) {
        sequence[(*length)++] = current->move;
        current = current->parent;
    }

    for (int i = 0; i < *length / 2; i++) {
        t_move temp = sequence[i];
        sequence[i] = sequence[*length - 1 - i];
        sequence[*length - 1 - i] = temp;
    }

}
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("Node (Value: %d, Position: (%d, %d))\n", root->value, root->loc.pos.x, root->loc.pos.y);

    for (int i = 0; i < root->child_count; i++) {
        printTree(root->children[i], level + 1);
    }
}