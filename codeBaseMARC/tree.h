//
// Created by jugar on 11/11/2024.
//

#ifndef TREE_H
#define TREE_H

#include "loc.h"
#include "map.h"
#include "moves.h"

typedef struct Node {
    t_localisation loc;
    int value;
    struct Node* children[9];
    int child_count;
    struct Node* parent;
    t_move move;
} Node;

Node* createNode(t_localisation loc, int value);
void addChild(Node* parent, Node* child);
void buildTree(Node* root, t_map map, int level);
void findOptimalPath(Node* root, int* min_value, Node** optimal_leaf);
void getOptimalSequence(Node* leaf, t_move* sequence, int* length);

int isOutOfMap(t_map map, t_localisation loc);
int isOnCrevasse(t_map map, t_localisation loc);

#endif // TREE_H