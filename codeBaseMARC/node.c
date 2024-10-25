//
// Created by melia on 25/10/2024.
//

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

p_node createNode(int val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;

    return nouv;
}
