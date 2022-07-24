#ifndef __STRING__
#define __STRING__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 字符串暴力匹配算法测试 */
int Index(char *str1,char *str2);
int index_kmp(char *str1, char *str2,int pos);
void get_next(char *str, int *next);

#endif