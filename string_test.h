#ifndef __STRING__
#define __STRING__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100 //定义数组最大容量
/* 字符串的结构 */
typedef struct 
{
    char data[MAX_SIZE];//数据域
    int length; //定义字符串长度
}SqStiring;

/* 字符串暴力匹配算法测试 */
int Index(char *str1,char *str2);
int index_kmp(char *str1, char *str2,int pos);
void get_next(char s[],int next[]);
#endif