//
// Created by melia on 25/10/2024.
//

#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H



struct s_node
{
    int value;
    struct s_node   *left, *right;
    int depth;
};

typedef struct s_node t_node, *p_node;

p_node createNode(int);
#endif //UNTITLED1_NODE_H