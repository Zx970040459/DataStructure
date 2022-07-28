#include "Hash_test1.h"

/* 创建哈希函数：取余法 */
int Hash(int key,int TableSize)
{
    return (key % TableSize);
}
/* 初始化哈希表 */
HashTable *InitHashTable(int TableSize)
{
    /* ①创建一个空的哈希表 */
    HashTable *hTable = NULL;
    /* ②防御机制，如果输入的哈希表大小小于0，则为其设置一个默认值 */
    if(TableSize <= 0)
    {
        TableSize = DEFAULT_SIZE;
    }
    /* ③为哈希表分配内存 */
    hTable = (HashTable *)malloc(sizeof(HashTable));
    /* ④防御机制，如果分配内存失败，则打印log，并返回NULL */
    if(NULL == hTable)
    {
        printf("哈希表内存分配失败！\n");
        return NULL;
    }
    /* ⑤初始化哈希表的容量为用户输入容量 */
    hTable->TableSize = TableSize;
    /* ⑥为哈希桶分配内存空间 */
    hTable->Thelists = (List*)malloc(sizeof(List)*TableSize);
    /* ⑦防御机制，如果分类内存失败，则打印log，并释放可能分配的异常内存 */
    if(NULL == hTable->Thelists)
    {
        printf("哈希桶内存分配失败！\n");
        free(hTable);
        return NULL;
    }
    /* ⑧为哈希桶对应的指针数组初始化链表结点 */
    for(int i=0;i<TableSize;i++)
    {
        hTable->Thelists[i] = (ListNode*)malloc(sizeof(ListNode));
        if(NULL == hTable->Thelists[i])
        {
            printf("哈希桶指针数组动态分配失败!\n");
            free(hTable->Thelists[i]);
            free(hTable);
            return NULL;
        }
        else
        {
            memset(hTable->Thelists[i],0,sizeof(ListNode)); //数组内元素置0
        }
    }//for
    /* ⑨返回初始化成功的哈希表的内存地址 */
    return hTable; //返回哈希表地址
}

int main()
{
    return 0;
}
