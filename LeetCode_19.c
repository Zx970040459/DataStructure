#include <stdio.h>
#include <stdlib.h>
/* LeetCode 第19题：删除链表的倒数第N个结点 */
typedef struct ListNode 
{
    int val;
    struct ListNode *next;
}ListNode;
/* 获取链表的长度 */
int getLength(struct ListNode* head) {
    int length = 0;
    while (head) {
        ++length;
        head = head->next;
    }
    return length;
}
/* 删除链表倒数第N个结点的实现函数：方法1 */
struct ListNode* removeNthFromEnd1(struct ListNode* head, int n) {
    /* 创建一个哑结点 */
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    int length = getLength(head);
    struct ListNode* cur = dummy;
    for (int i = 1; i < length - n + 1; ++i) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}

/* 方法2：双指针 */
struct ListNode* removeNthFromEnd2(struct ListNode* head, int n) 
{
    /* ①创建一个哑结点 */
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    /* ②哑结点指向链表的头结点 */
    dummy->next = head;
    /* ③创建两个遍历指针，指向dummy */
    ListNode *pPrev = dummy;
    ListNode *pMove = dummy;
    /* ④后移pMove指针，直到pMove和pPrev指针之间相差n个结点 */
    for(int i = 0;i<n+1;i++)
    {
        pMove = pMove->next;
    }
    /* ⑤移动双指针，直到pMove指针指向NULL，即链表遍历结束 */
    while (pMove != NULL)
    {
        pPrev = pPrev->next;
        pMove = pMove->next;
    }
    /* ⑥定义要删除的结点 */
    ListNode *delNode = pPrev->next;
    /* ⑥-1删除操作 */
    pPrev->next = delNode->next;
    free(delNode);
    
    ListNode *retNode = dummy->next;
    free(dummy);
    
    return retNode;
}

int main()
{
    return 0;
}
