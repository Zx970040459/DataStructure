#ifndef __QUEUE__
#define __QUEUE__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bool char
#define true 1
#define false 0

typedef int Elemtype;
/* 创建链表结点类型结构体---单链表 */
typedef struct Node
{
    Elemtype data;
    struct Node *next;
}SNode;

/* 创建队列元素类型结构体 */
typedef struct Q
{
    SNode *frontNode; //顶部结点
    SNode *tailNode;  //尾部结点
    int size_queue;   //队列长度
}Queue;
/* 创建结点 */
SNode *creatNode(Elemtype data);
/* 创建队列 */
Queue *creatQueue();

/* 判断队列是否为空 */
bool isEmpty_Queue(Queue *q);
/* 进队 */
bool push_Queue(Queue *q,int data);
/* 出队 */
bool pop_Queue(Queue *q);

#endif