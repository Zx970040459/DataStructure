/* 哈希表的C实现
  查找使用的方法是“除留余数法”，解决冲突使用的方法是“链地址法”。
*/
#include "Hash.h"
HASH_TABLE* create_hash_table()
{
    HASH_TABLE* pHashTbl = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
    memset(pHashTbl, 0, sizeof(HASH_TABLE));
    return pHashTbl;
}
//在哈希表中查找数据
NODE* find_data_in_hash(HASH_TABLE* pHashTbl, int data)
{
    NODE* pNode;
    if(NULL ==  pHashTbl)
        return NULL;

    if(NULL == (pNode = pHashTbl->value[data % 10]))
        return NULL;

    while(pNode){
        if(data == pNode->data)
            return pNode;
        pNode = pNode->next;
    }
    return NULL;
}
//在哈希表中插入数据
STATUS insert_data_into_hash(HASH_TABLE* pHashTbl, int data)
{
    NODE* pNode;
    if(NULL == pHashTbl)
        return FALSE;

    if(NULL == pHashTbl->value[data % 10]){
        pNode = (NODE*)malloc(sizeof(NODE));
        memset(pNode, 0, sizeof(NODE));
        pNode->data = data;
        pHashTbl->value[data % 10] = pNode;
        return TRUE;
    }

    if(NULL != find_data_in_hash(pHashTbl, data))
        return FALSE;

    pNode = pHashTbl->value[data % 10];
    while(NULL != pNode->next)
        pNode = pNode->next;

    pNode->next = (NODE*)malloc(sizeof(NODE));
    memset(pNode->next, 0, sizeof(NODE));
    pNode->next->data = data;
    return TRUE;
}
//从哈希表中删除数据
STATUS delete_data_from_hash(HASH_TABLE* pHashTbl, int data)
{
    NODE* pHead;
    NODE* pNode;
    if(NULL == pHashTbl || NULL == pHashTbl->value[data % 10])
        return FALSE;

    if(NULL == (pNode = find_data_in_hash(pHashTbl, data)))
        return FALSE;

    if(pNode == pHashTbl->value[data % 10]){
        pHashTbl->value[data % 10] = pNode->next;
        free(pNode);
        return TRUE;
    }

    pHead = pHashTbl->value[data % 10];
    while(pNode != pHead ->next)
        pHead = pHead->next;
    pHead->next = pNode->next;

}
int main()
{
    HASH_TABLE* hashtable=create_hash_table();
    insert_data_into_hash(hashtable,1);
    //insert_data_into_hash(hashtable,4);
    insert_data_into_hash(hashtable,11);
    insert_data_into_hash(hashtable,21);
    NODE* node1=find_data_in_hash(hashtable,11);
    NODE* node2=find_data_in_hash(hashtable,21);
    printf("hashtable 1 : %d \n",hashtable->value[1]->data);
    if(hashtable->value[2]==NULL) printf("hashtable 2 is null\n");
    printf("hashtable 1 : %d \n",node1->data);
    printf("hashtable 1 : %d \n",node2->data);
    delete_data_from_hash(hashtable,21);
        NODE* node3=find_data_in_hash(hashtable,21);
    if(node3==NULL) printf("21 is cancel\n");
    else printf("hashtable 1 : %d \n",node3->data);
    return 0;
}