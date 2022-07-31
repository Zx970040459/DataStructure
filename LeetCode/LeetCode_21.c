/* 合并两有序链表
    链接：https://leetcode.cn/problems/merge-two-sorted-lists/ 
*/
#include <stdio.h>

/* 创建链表结点结构体 */
typedef struct Node
{
    struct Node *next;
    int val;
}ListNode;

/* 递归的方法 */
ListNode *test(ListNode *l1,ListNode *l2)
{
    if(l1 == NULL)
    {
        return l2;
    }
    else if(l2 == NULL)
    {
        return l1;
    }
    else if(l1->val < l2->val)
    {
        l1->next = test(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next = test(l1,l2->next);
        return l2;
    }
}
int main()
{
    return 0;
}