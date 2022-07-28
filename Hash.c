#include "Hash.h"

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
    /* ⑥为哈希桶分配内存空间：哈希桶保存的是索引的数组 */
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
    return hTable; 
}

/* 哈希表插入数值，数值为键值对 */
void Insert_HashTable(HashTable *hashtable,int key,void *value)
{
    /* ①初始化一个空的元素，用于判断原哈希表中是否存在要插入的键值 */
    Element e = NULL;
    /* ②初始化一个空的元素，用于插入 */
    Element tmp = NULL;
    /* ③初始化一个空表 */
    List L = NULL;
    /* ④判断原表中是否存在要插入的键值 */
    e = Find(hashtable,key);
    /* ⑤如果原表中不存在要插入的键值，则执行插入操作 */
    if(NULL == e)
    {
        /* ⑤-1为要插入的结点分配内存 */
        tmp = (Element)malloc(sizeof(ListNode));
        /* ⑤-2防御机制，如果分配内存失败则执行 */
        if(NULL == tmp)
        {
            printf("tmp内存分配失败!\n");
            return ;
        }
        /* ⑤-3前插法插入结点 */
        L = hashtable->Thelists[Hash(key,hashtable->TableSize)];
        tmp->data = value;
        tmp->key = key;
        tmp->next = L->next;
        L->next = tmp;
    }
    /* ⑥如果原表中存在欲插入的键值，则打印log并结束函数 */
    else
    {
        printf("键值已存在！\n");
        return;
    }
}

/* 从哈希表中查找元素 */
Element Find(HashTable *HashTable,int key)
{
    /* ①创建一个空表 */
    List L = NULL;
    /* ②初始化一个空的元素 */
    Element e = NULL;
    /* ③查找键值在哈希表中的哈希桶下标 */
    int i =Hash(key,HashTable->TableSize);
    /* ④找到哈希桶的头结点L的地址 */
    L = HashTable->Thelists[i];
    /* ⑤因为头结点不存储数据，所以找到头结点的下一个结点 */
    e = L->next;
    /* ⑥遍历判断元素中的键值是否等于要查找的键值，如果找到则退出循环 */
    while(e != NULL && e->key != key)
    {
        e = e->next;
    }
    /* ⑦返回要查找的键值的地址 */
    return e;
}
Element Delete(HashTable *hashtable,int key)
{
    Element e = NULL,last = NULL;
    List L = NULL;
    int i = Hash(key,hashtable->TableSize);
    L = hashtable->Thelists[i];

    last = L;
    e = L->next;
    while(e != NULL && e->key != key)
    {
        last = e;//?
        e = e->next;
    }
    if(e != NULL)
    {
        last->next = e->next;
        free(e);
    }
}

/* 哈希表中元素提取数据 */
void *Retrieve(Element e)
{
    return e?e->data:NULL;
}


int main()
{
    char *elems[] = {"徐小峰","张家栋","许三多"};
    HashTable *hashtable = NULL;
    hashtable = InitHashTable(31);
    Insert_HashTable(hashtable,1,elems[0]);
    Insert_HashTable(hashtable,2,elems[1]);
    Insert_HashTable(hashtable,3,elems[2]);
    for(int i=1;i<4;i++)
    {
        Element e = Find(hashtable,i);
        if(e)
        {
            printf("数据内容为：%s\n",(const char*)Retrieve(e));
        }
        else
        {
            printf("没有找到数据!key[%d]\n",i);
        }
    }//for
    return 0;
}
