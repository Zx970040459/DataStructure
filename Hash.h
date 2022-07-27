#ifndef __HASH__
#define __HASH__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
typedef int STATUS;
#define HASH_SIZE 100
#define NULLKEY -6753453
/* 哈希表结构 */
typedef struct 
{
    int *elem; //数据元素的基地址，用于动态分配内存
    int count;
}HashTable; 

//定义哈希表和基本数据节点
typedef struct _NODE
{
    int data;
    struct _NODE* next;
}NODE;
//创建哈希表
typedef struct _HASH_TABLE
{
    NODE* value[10];
}HASH_TABLE;

/* 初始化哈希表 */
int Init_HashTalbe(HashTable *H);
#endif