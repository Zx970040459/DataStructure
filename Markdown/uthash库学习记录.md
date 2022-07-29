# uthash 库学习记录--应用篇

## uthash库是什么：
1. *uthash* 是C的比较优秀的开源代码，它实现了常见的hash操作函数，例如查找、插入、删除等。该套开源代码采用宏的方式实现hash函数的相关功能，支持C语言的任意数据结构作为key值（可以是自定义的struct或基本数据类型）;

## uthash 库的使用场景
1. 添加/替换（add/replace)
2. 查找(find)
3. 删除(delete)
4. 统计(count)
5. 迭代器(iterate)
6. 排序(sort)

## uthash库常用接口详解
### 一. 使用接口前的准备工作

> 使用接口之前，需要定义一个哈希表

```c
/* 定义哈希表结构体 */
 struct hashTable
 {
     int key;
     int val;
     UT_hash_handle hh;
 };

 /* 定义一个哈希表 */
 struct hashTable *My_hashtable = NULL;
```

### 二. 哈希表查找接口

1. HASH_FIND_INT(hashtable,&key,tmp);
    入口参数1：hashtable:哈希表；
    入口参数2：&key:**要查找的键值的地址**；
    入口参数3：tmp:哈希表结构的结构体指针，如果找到键值，该值非空；


>自定义查找接口函数的例程如下：
```c
/* 创建一个哈希表查找接口函数 */
struct hashTable *Hash_Find(int ikey)
{
    struct hashTable *tmp;
    HASH_FIND_INT(My_hashtable,&ikey,tmp);
    return tmp;
}
```

### 三. 哈希表插入接口

1. HASH_ADD_INT(hashtable,key,tmp);
    入口参数1：hashtable:哈希表
    入口参数2：key:要插入的键值
    入口参数3：tmp:哈希表结构的结构体指针

>自定义插入接口函数例程：
```c
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
```

## uthash库的典型应用举例：
> [LeetCode 第一题：求两个数的和问题求解;来源：力扣（LeetCode）](https://leetcode.cn/problems/two-sum)

  ```c
  int* twoSum(int* nums, int numsSize, int target, int*returnSize) 
      {
          //初始化自定义哈希表结构体指向空
          hashtable = NULL;
          //循环遍历输入的nums数组
          for (int i = 0; i < numsSize; i++)
          {
              struct hashTable* it = Hash_Find(target - nums[i]);
              if (it != NULL) 
              {
                  int* ret = malloc(sizeof(int) * 2);
                  ret[0] = it->val, ret[1] = i;
                  *returnSize = 2;
                  return ret;//返回结果
              }//if
              Hash_Insert(nums[i], i); //两个参数：数组中的元素，数组的下标
          }//for
          *returnSize = 0;
          return NULL;
      }
  ```
## uthash库的使用流程-待完善补充
1. 定义结构体
   ```c
   #include "uthash.h"
   
    struct my_struct {
        int id;            /* we'll use this field as the key */
        char name[10];
        UT_hash_handle hh; /* makes this structure hashable */
    };
   ```
2. 声明哈希表
    **必须将自定义的结构体指针定义为NULL！**因为uthash库中对于空表和非空表会执行不同的操作。
    
    ```c
    struct my_struct *g_users = NULL;  /* important! initialize to NULL */
    ```
3. 添加items
    ```c
    void add_user(int user_id, char *name)
    {
        struct my_struct *s;
        
        HASH_FIND_INT(g_users, &user_id, s);
        if(NULL == s)
        {
            s = malloc(sizeof(struct my_struct));
            s->id = user_id;
            HASH_ADD_INT(g_users, id, s );  /* id: name of key field */
        }
        strcpy(s->name, name);
    }
    ```
    **注意：**一旦结构的item添加到了hash表，就不要试图去修改对应item的key值，除非你已经把它从hash表删除。

    如果我们想将g_users的全局链表暴露给应用者来制定，从而可以在一个应用中使用多个链表，那需要注意正确的使用是采用二级指针（因为宏修改的是指针本身，而不仅仅是它所指向的内容）：
    ```c
    void add_user(struct my_struct **users, int user_id, char *name)
    {
        HASH_ADD_INT( *users, id, s );
    }
    ```

4. 替换items
    HASH_REPLACE宏等价于HASH_ADD宏，只是它们首先尝试查找和删除项。如果它发现并删除一个项，它还将返回该项指针作为输出参数。
    ```c
    HASH_REPLACE();
    ```
5. 查找items
    &user_id为指向key的指针。
    ```c
    struct my_struct *find_user(int user_id)
    {
        struct my_struct *s;
    
        HASH_FIND_INT(g_users, &user_id, s );  /* s: output pointer */
        return s;
    }
    ```
6. 删除items
    ```c
    void delete_user(struct my_struct *user)
    {
        HASH_DEL(g_users, user);  /* user: pointer to deletee */
        free(user);             /* optional; it's up to you! */
    }
    ```
    g_user是哈希表，user是用户自定义结构体。
    uhash不会释放哈希表内存，HASH_DEL只会删除结点，但是不会释放内存，需要用户自行释放；

    如果仅删除哈希表中的链表结点，但是不需要释放内存，则可以使用如下宏：
    ```c
    HASH_CLEAR(hh,g_user);
    ```
7. 统计items
    ```c
    unsigned int num_users;
    num_users = HASH_COUNT(g_users);
    printf("there are %u users\n", num_users);
    ```
    当hash表g_users为NULL时，将得到0。
8. 迭代哈希表
    可以使用hh->next指针遍历打印链表
    ```c
    void print_users()
    {
        struct my_struct *s;
    
        for(s=users; s != NULL; s=s->hh.next)
        {
            printf("user id %d: name %s\n", s->id, s->name);
        }
    }
    ```
9. 排序哈希表
    默认情况下，hash表的顺序与你插入的顺序是一致的。你可以通过HASH_SORT宏对整个hash表进行排序：
    ```c
    HASH_SORT(g_users, name_sort);
    ```
    name_sort是你自己提供的比较算法。他必须接受两个items作为参数，且返回值为int，返回值规则与标准C的strcmp和qsort一致：小于时返回负数，相等返回0，大于则返回正数。
    ```c
    int sort_function(void *a, void *b)
    {
        /* compare a to b (cast a and b appropriately)
        * return (int) -1 if (a < b)
        * return (int)  0 if (a == b)
        * return (int)  1 if (a > b)
        */
    }
    ```
    下面是两个排序的实例：
    ```c
    int name_sort(struct my_struct *a, struct my_struct *b)
    {
        return strcmp(a->name,b->name);
    }
    
    int id_sort(struct my_struct *a, struct my_struct *b)
    {
        return (a->id - b->id);
    }
    
    void sort_by_name()
    {
        HASH_SORT(users, name_sort);
    }
    
    void sort_by_id()
    {
        HASH_SORT(users, id_sort);
    }
    ```

