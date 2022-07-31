#include <stdio.h>
#include <stdlib.h>
/* 两数相加问题 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode 
{
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = NULL;//创建一个指向返回值链表的指针
    struct ListNode* newNode = NULL;//创建一个结点指针
    int sum = 0,carry = 0;

    /* 遍历链表l1和l2 */
    while(l1 != NULL || l2 != NULL)
    {
        int a = l1 ? l1->val : 0;//如果l1不为空，则执行a = l1->val;否则执行a = 0;
        int b = l2 ? l2->val : 0;//如果l2不为空，则执行b = l2->val;否则执行b = 0;
        sum = a + b + carry; //求和a,b并加上进位值
        carry = sum/10; //进位
        if(head == NULL)//如果链表为空，则创建结点
        {
            head = newNode = (struct ListNode*)malloc(sizeof(struct ListNode));//为结点分配内存
            newNode->val = sum%10;//结点初始化
            newNode->next = NULL;
        }
        else
        {
            newNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->next->val = sum%10;
            newNode = newNode->next;
            newNode->next = NULL;      
        }
        if(l1)
            l1 = l1->next;//遍历l1
        if(l2)
            l2 = l2->next;//遍历l2
    }//while
    /* 如果最高位的和大于10，需要再申请一个结点用于存放最高位的进位 */
    if(carry > 0)
    {
        newNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next->val = carry;
        newNode = newNode->next;
        newNode->next = NULL;
    }
    return head;
}
int main()
{
    return 0;
}