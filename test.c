/* 反转链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	struct Node *next;
	int data;
}LinkList,ListNode;
LinkList* reverseList(LinkList* head) {
    LinkList* prev = NULL;
    LinkList* curr = head;
    while (curr) {
        LinkList* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
} 
void AddNode(LinkList *head,int data)
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

int main()
{
	LinkList *head = (LinkList *)malloc(sizeof(LinkList));
	//head->data = -1;
	head->next = NULL;
	int len = 5;

	printf("请输入要反转的链表数�?!\n");
	for(int i=0;i<len;i++)
	{
		int data;
		scanf("%d",&data);
		AddNode(head,data);
	}
	LinkList *pMove = reverseList(head->next);
	printf("反转后：\n");
	while (pMove!=NULL)
	{
		printf("%d",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
	return 0;
}
