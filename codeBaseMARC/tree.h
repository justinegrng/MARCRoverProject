//
// Created by jugar on 11/11/2024.
//

#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int value;
    struct TreeNode* child1;
    struct TreeNode* child2;
    struct TreeNode* child3;
} TreeNode;

TreeNode* createNode(int value);
void addChild1(TreeNode* parent, int value);
void addChild2(TreeNode* parent, int value);
void addChild3(TreeNode* parent, int value);
void freeTree(TreeNode* root);
void buildSimpleTree(TreeNode* root);
int findMinLeaf(TreeNode* root);
void printPathToMinLeaf(TreeNode* root, int minLeaf);


#endif // TREE_H