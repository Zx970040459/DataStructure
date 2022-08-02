#include <stdio.h> //printf,scanf
#include <stdlib.h>//malloc
/* 定义链表结点数据类型 */
typedef int ElemType;
/* 定义链表结点结构体 */
typedef struct Node
{
	struct Node *next;
	ElemType data;
}ListNode,LinkList;
/* 获取链表长度 */
int GetLength(LinkList *head)
{
	int len = 0;
	ListNode *pMove = head->next;
	while(pMove != NULL)
	{
		len++;
		pMove = pMove->next;
	}
	return len;
}
/* 尾插 */
void AddNode(LinkList *head,ElemType data)
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode *lastNode = head;
	while(lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	newNode->data = data;
	newNode->next = NULL;
	lastNode->next = newNode;
}
/* 单次冒泡 */
void Bubble(LinkList *head)
{
	ListNode *pTail = head;
	ListNode *pCurrent = pTail->next;
	ListNode *pNext = pCurrent->next;
	int len = GetLength(head);
	for(int i=1;i<len;i++)
	{
		if(pCurrent->data > pNext->data)
		{
			pCurrent->next = pNext->next;
			pNext->next = pCurrent;
			pTail->next = pNext;
		}
		pTail = pTail->next;
		pCurrent = pTail->next;
		pNext = pCurrent->next;
	}
}
/* 冒泡排序 */
void BubbleSort(LinkList *head)
{
	int len = GetLength(head);
	for(int i=len;i>0;i--)
	{
		printf("i=%d\n",i);
		Bubble(head);
	}
}
int main()
{
	LinkList *head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	head->data = -1;
	int len = 0; //定义链表长度存储变量
	printf("请输入链表的长度：\n");
	scanf("%d",&len);
	printf("请输入要排序的数据！\n");
	for(int i=0;i<len;i++)
	{
		int val;
		scanf("%d",&val);
		AddNode(head,val);
	}

	BubbleSort(head); //排序
	LinkList *pMove = head->next; //遍历指针
	while(pMove)
	{
		printf("%d",pMove->data);
		pMove = pMove->next;
	}
	return 0;
}