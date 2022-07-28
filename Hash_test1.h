#ifndef __HASH_TEST__
#define __HASH_TEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_SIZE 16
/* 定义结点类型结构体 */
typedef struct Node
{
    struct Node *next; 
    int key;//键值
    void *data; //数据域
}ListNode;
/* 定义两个类型重定义 */
typedef ListNode *List;
typedef ListNode *Element;

/* 定义哈希表类型结构体 */
typedef struct _HashTable
{
    int TableSize;
    List *Thelists;
}HashTable;
/* 创建哈希函数 */
int Hash(int key,int TableSize);
#endif