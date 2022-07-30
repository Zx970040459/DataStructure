#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

int main()
{
    return 0;
}
/* 定义哈希表结构体 */
struct hashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

/* 定义一个哈希表 */
struct hashTable *My_hashtable = NULL;

/* 创建一个哈希表查找接口函数 */
struct hashTable *Hash_Find(int ikey)
{
    struct hashTable *tmp;
    HASH_FIND_INT(My_hashtable,&ikey,tmp);
    return tmp;
}

/* 创建一个哈希表插入键值对接口函数 */
void Hash_Insert(int ikey,int ival)
{
    struct hashTable *it = Hash_Find(ikey);
    if(it == NULL)
    {
        struct hashTable *tmp = (struct hashTable*)malloc(sizeof(struct hashTable));
        tmp->key = ikey;
        tmp->val = ival;
        HASH_ADD_INT(My_hashtable,key,tmp);
    }
    else
    {
        it->val = ival;
    }
}

//求和
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    My_hashtable = NULL; //初始化哈希表结构体指针
    for (int i = 0; i < numsSize; i++) 
    {
        struct hashTable* it = Hash_Find(target - nums[i]);
        if (it != NULL) 
        {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        Hash_Insert(nums[i], i);
    }//for
    *returnSize = 0;
    return NULL;
}

gets_s();