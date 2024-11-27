//
// Created by jugar on 11/11/2024.
//

#ifndef TREE_H
#define TREE_H

#include "loc.h"
#include "map.h"
#include "moves.h"

/**
 * @brief Structure for a node of the tree
 */
typedef struct Node {
    t_localisation loc;
    int value;
    struct Node* children[9];
    int child_count;
    struct Node* parent;
    t_move move;
} Node;

/**
 * @brief Function to create a node
 * @param loc : the localisation of the node
 * @param value : the value of the node
 * @return the node
 */
Node* createNode(t_localisation loc, int value);

/**
 * @brief Function to add a child to a parent
 * @param parent : the parent node
 * @param child : the child node
 * @return none
 */
void addChild(Node* parent, Node* child);

/**
 * @brief Function to build a tree
 * @param root : the root of the tree
 * @param map : the map
 * @param level : the level of the tree
 * @return none
 */
void buildTree(Node* root, t_map map, int level);

/**
 * @brief Function to find the optimal path
 * @param root : the root of the tree
 * @param min_value : the minimum value
 * @param optimal_leaf : the optimal leaf
 * @return none
 */
void findOptimalPath(Node* root, int* min_value, Node** optimal_leaf);

/**
 * @brief Function to get the optimal sequence
 * @param leaf : the leaf node
 * @param sequence : the sequence of moves
 * @param length : the length of the sequence
 * @return none
 */
void getOptimalSequence(Node* leaf, t_move* sequence, int* length);

/**
 * @brief Function to print the tree
 * @param root : the root of the tree
 * @param level : the level of the tree
 * @return none
 */
void printTree(Node* root, int level);

#endif // TREE_H