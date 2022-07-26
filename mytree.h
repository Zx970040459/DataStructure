#ifndef __MYTREE__
#define __MYTREE__
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE 100

typedef char ElemType;  //int类型重命名
typedef struct Node
{
    int data;
    struct Node *treeLeft;
    struct Node *treeRight;
}tree_t;

/* 树的双亲孩子表示法 */

/* 定义孩子结点类型结构体 */
typedef struct CTNode
{
    int child; //孩子结点的下标
    struct CTNode *next;//指向下一个孩子结点的指针
}*ChildPtr;

/* 表头结构 */

typedef struct 
{
    ElemType data; //存放在树中结点的数据
    int parent;    //指向双亲的下标
    ChildPtr firstchild;//指向第一个孩子的指针
}CTBox;
/* 树结构 */
typedef struct 
{
    CTBox nodes[MAX_TREE_SIZE];//结点数组
    int r,n;
};

/* 二叉树的存储结构 */
typedef struct BitNode
{
    ElemType data;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;
/* 线索二叉树的结构 */
/* 线索存储标志位
    Link(0)表示指向左右孩子的指针
    Thread(1)表示指向前驱后继的线索
 */
typedef enum{Link,Thread}PointerTag;
typedef struct BihrNode
{
    ElemType data;
    struct BihrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BithrNode,*BiThrTree;
void createBiTree(BiTree *T);
void PreOrderTravers(BiTree T,int level);
void visit(char c,int level);
void creatBithrTree(BiThrTree *T);
#endif