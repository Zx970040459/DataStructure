#include <stdio.h>
/* 实现简单的排序算法：
    1、冒泡排序
    2、选择排序
    3、插入排序
 */

/* 链表的冒泡排序实现 */
typedef struct Node
{
    struct Node *next;
    int data;
}ListNode;
void add(ListNode *head,int data)
{
    ListNode *p,*L;
}
/* 数组冒泡排序算法实现 */
void Bubble(int a[],int len)
{
    int tmp = 0;
    for(int i=0;i<len-1;i++)
    {
        if(a[i] > a[i+1])
        {
            tmp = a[i];
            a[i] = a[i+1];
            a[i+1] = tmp;
        }
    }
}
void BubbleSort(int a[],int len)
{
    for(int n = len;n > 0; n--)
    {
        Bubble(a,n);
    }
}
void bubble_sort_test()
{
    printf("【冒泡排序】测试用例!\n");
    int a[10] = {9,2,3,6,3,1,2,3,5,0};
    printf("排序前的数组:");
    for(int i=0;i<10;i++)
        printf("%d",a[i]);
    BubbleSort(a,10);
    printf("\n排序后的数组:");
    for(int i=0;i<10;i++)
        printf("%d",a[i]);
    printf("\n");
}
/* 冒泡排序算法实现--END */

/* 选择排序算法实现 */
int FindMaxPos(int a[],int len)//寻找最大值的位置
{
    int max = 0;
    int pos = 0;
    for(int i=0;i<len;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
            pos = i;
        }
    }
    return pos;
}

void SelectionSort(int a[],int len)
{
    while(len>1)
    {
        int pos = FindMaxPos(a,len);
        int tmp = a[pos];//保存最大值
        a[pos] = a[len-1];
        a[len-1] = tmp;
        len--;
    }
}
void select_sort_test()
{
    printf("【选择排序】测试用例!\n");
    int a[10] = {9,2,3,6,3,1,2,3,5,0};
    printf("排序前的数组:");
    for(int i=0;i<10;i++)
        printf("%d",a[i]);
    SelectionSort(a,10);
    printf("\n排序后的数组:");
    for(int i=0;i<10;i++)
        printf("%d",a[i]);
    printf("\n");
}
/* 选择排序算法实现--END */
/* 插入排序算法实现 */
void insert(int a[],int n)
{
    int key = a[n];
    int i = n;
    while (a[i-1] > key)
    {
        a[i] = a[i-1];
        i--;
        if(i == 0)
            break;
    }//while
    a[i] = key;
}
void InsertionSort(int a[],int len)
{
    for(int i =1;i<len;i++)
    {
        insert(a,i);
    }
}
void insert_sort_test()
{
    printf("【插入排序】测试用例!\n");
    int a[10] = {9,2,3,6,3,1,2,3,5,0};
    printf("排序前的数组:");
    for(int i=0;i<10;i++)
        printf("%d",a[i]);
    InsertionSort(a,10);
    printf("\n排序后的数组:");
    for(int i=0;i<10;i++)
        printf("%d",a[i]);
    printf("\n");
}
/* 插入排序算法实现--END */
int main()
{
    insert_sort_test();
    return 0;
}