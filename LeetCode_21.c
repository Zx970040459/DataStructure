#include <stdio.h>
typedef struct Node
{
    struct Node *next;
    int val;
}ListNode;

int main()
{

    return 0;
}
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


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if (l1 == nullptr) {
//             return l2;
//         } else if (l2 == nullptr) {
//             return l1;
//         } else if (l1->val < l2->val) {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         } else {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// };
