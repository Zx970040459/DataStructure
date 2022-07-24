#ifndef __MYTREE__
#define __MYTREE__
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *treeLeft;
    struct Node *treeRight;
}tree_t;

#endif