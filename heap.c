#include <stdio.h>
/* 交换数组元素值 */
void Swap(int a[],int i,int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
/* 堆操作中的找到根节点 */
void Heapify(int tree[],int n,int i)
{
    if(i >= n)
        return;//递归出口
    int c1 = 2*i+1;
    int c2 = 2*i+2;
    int max = i;
    if(c1 < n && tree[c1] > tree[max])
        max = c1;
    if(c2 < n && tree[c2] > tree[max])
        max = c2;
    if(max != i)
    {
        Swap(tree,max,i);
        Heapify(tree,n,max);
    }
}
/* 把一个数组创建成一个堆 */
void BuildHeap(int tree[],int n)
{
    int last_node = n-1;
    int parent_node = (last_node-1)/2;
    for(int i = parent_node;i>=0;i--)
    {
        Heapify(tree,n,i);
    }
}
/* 堆排序 */
void HeapSort(int tree[],int n)
{
    BuildHeap(tree,n);
    for(int i = n-1;i >= 0;i--)
    {
        Swap(tree,i,0);
        Heapify(tree,i,0);
    }
}
int main()
{
    int tree[] = {2,5,3,1,10,4};
    int n = 6;
    HeapSort(tree,n);
    for(int i=0;i<6;i++)
        printf("%d",tree[i]);
    return 0;
}