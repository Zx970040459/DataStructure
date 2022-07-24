#ifndef __STACK__
#define __STACK__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/******************************顺序栈**********************************/
#define bool char
#define true 1
#define false 0
/* ************************************* */
#define STACK_MAX_SIZE 100 //定义栈容量
typedef struct stack_1
{
    int data[STACK_MAX_SIZE];
    int pTop; //定义栈顶指针
}Stack_1_t;

/* 初始化栈 */
bool Init_Stack_1(Stack_1_t *stack);
/* 判断栈是否为空 */
bool is_Empty_Stack_1(Stack_1_t *stack);
/* 入栈 */
bool push_Stack_1(Stack_1_t *stack,int data);
/* 出栈 */
bool pop_Stack_1(Stack_1_t *stack,int *data);
/* 读取栈顶元素 */
bool get_Top_Stack_1(Stack_1_t *stack,int *data);

/******************************链式栈**********************************/
typedef int elemtype;
/* 创建结点类型结构体 */
typedef struct Node
{
    struct Node *next;
    int data;
}LinkList;

/* 定义栈类型 */
typedef struct stack
{
    LinkList *stack_Top;//定义栈顶标记
    int stack_Size;//栈大小
}Stack_t;
/* 创建结点 */
LinkList *creatNode(int data);
/* 栈初始化 */
Stack_t *Init_Stack();
/* 入栈操作 */
void push_Stack(Stack_t *myStack,int data);
/* 出栈操作 */
void pop_Stack(Stack_t *myStack);
/* 读栈顶元素，如若栈非空，返回栈顶元素 */
Stack_t get_Top(Stack_t *myStack);
/* 获取栈顶元素 */
int top_Stack(Stack_t *myStack);
/* 判断栈是否为空 */
int isEmpty_Stack(Stack_t *myStruct);
/* 栈的应用：括号匹配问题求解 */
int kuohaopipei();
/* 释放栈，并释放栈占用的空间 */
void DestroyStack(Stack_t *myStack);

#endif