#include "queue.h"

/* 创建结点 */
SNode *creatNode(Elemtype data)
{
    SNode *newNode = (SNode *)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
/* 创建队列 */
Queue *creatQueue()
{
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->frontNode = newQueue->tailNode = NULL;
    newQueue->size_queue = 0;

    return newQueue;
}
/* 判断队列是否为空 */
bool isEmpty_Queue(Queue *q)
{

}
/* 入队 */
bool push_Queue(Queue *q,int data)
{
    SNode *newNode = creatNode(data);
    if(q->size_queue == 0)
    {
        q->frontNode = q->tailNode = newNode;
    }
    else
    {
        q->tailNode->next = newNode;
        q->tailNode = newNode;
    }
    q->size_queue++; //队列长度自增
}
/* 出队 */
bool pop_Queue(Queue *q)
{
    if(q->size_queue == 0)
    {
        printf("空队列！\n");
        return false;
    }
    else
    {
        SNode *nextNode = q->frontNode->next;
        free(q->frontNode);
        q->frontNode = nextNode;
        q->size_queue --;
        return true;
    }
}

/******************************main**************************/
int main()
{
    Queue *q = creatQueue();
    push_Queue(q,10);
    push_Queue(q,11);
    push_Queue(q,12);
    while(q->size_queue != 0)
    {
        printf("队列中的元素为：%d\n",q->frontNode->data);
        pop_Queue(q);
    }
    return 0;
}

