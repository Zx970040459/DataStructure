/* 链表冒泡排序 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef int ElemType ;

typedef struct Node
{
	struct  Node *next;
	ElemType data;
}ListNode,LinkList;
/* 遍历计算链表长度 */
int GetLength(LinkList *head)
{
	int length = 0; //定义计数器
	ListNode *pMove = head->next;
	while(pMove != NULL)
	{
		length++;
		pMove = pMove->next;
	}
	return length;//返回链表长度
}
/* 链表单次冒泡 */
void Bubble(LinkList *head)
{
	ListNode *pTail = head;
	ListNode *pCurrent = pTail->next;
	ListNode *pNext = pCurrent->next;
	int length = GetLength(head);//获取链表长度
	while(length > 1)
	{
		length--;
		if(pCurrent->data > pNext->data)
		{//交换结点
			pCurrent->next = pNext->next;
			pNext->next = pCurrent;
			pTail->next = pNext;
		}
		//指针依次后移
		pTail = pTail->next;
		pCurrent = pTail->next;
		pNext = pCurrent->next;
	}
}
/* 定义链表结点插入函数--尾插法 */
void AddNode(LinkList *head,ElemType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	ListNode *pLast = head;
	while(pLast->next != NULL)
	{
		pLast = pLast->next;
	}
	newNode->data = data;
	newNode->next = NULL;
	pLast->next = newNode;
}
void BubbleSort(LinkList *head)
{
	int len = GetLength(head);
	while(len > 0)
	{
		Bubble(head);
		len--;
	}
}
void Bubble_Arry(int a[],int len)
{
	int tmp = 0;
	for(int i=1;i<len;i++)
	{
		if(a[i-1] < a[i])
		{
			tmp = a[i];
			a[i] = a[i-1];
			a[i-1] = tmp;
		}
	}
}
void BubbleSort_Arry(int a[],int len)
{
	for(int i = len;i > 0; i--)
	{
		Bubble_Arry(a,len);
	}
}
int* bubbleSort(int a[],int n)
{
	if(a == NULL|| n < 2)return a;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j] > a[j+1])
			{
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}
int test_LinkList()
{
	LinkList *head = (LinkList*)malloc(sizeof(LinkList));
	printf("请输入想要排序的序列长度!\n");
	int len = 0;
	scanf("%d",&len);
	printf("请输入想要排序的序列数值!\n");
	int data = 0;
	for(int i=0;i<len;i++)
	{
		scanf("%d",&data);
		AddNode(head,data);
	}
	printf("排序前的序列为:");
	ListNode *pMove = head->next;
	while(pMove)
	{
		printf("%d",pMove->data);
		pMove = pMove->next;
	}
	BubbleSort(head);
	pMove = head->next;
	printf("排序后的序列为:");
	while(pMove)
	{
		printf("%d",pMove->data);
		pMove = pMove->next;
	}
	return 0;
}
int test_Arry()
{
	int a[9] = {1,2,5,3,9,7,6,8,0};
	Bubble_Arry(a,9);
	printf("排序结果为:");
	for(int i=0;i<9;i++)
		printf("%d",a[i]);
	return 0;
}
int main()
{
	int a[9] = {1,2,5,3,9,7,6,8,0};
	bubbleSort(a,9);
	for(int i=0;i<9;i++)
		printf("%d",a[i]);
	return 0;
}