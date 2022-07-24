#include "string_test.h"
/* 暴力BF匹配算法 */
int main()
{
    //printf("the pos is:%d\n",Index("a","caa")); 
    index_kmp("abacc","acc",1);

    return 0;
}
/* BF算法 */
int Index(char *str1,char *str2)
{
    int i,j = 0; //定义计数指针变量
    int length1 = strlen(str1); //定义字符串1长度
    int length2 = strlen(str2); //定义字符串2长度
    printf("the length1 is: %d",length1);
    printf("the length2 is: %d",length2);
    while(i <= length1 && j <= length2)
    {
        if(str1[i] == str2[j])
        {
            i++;
            j++; //继续比较后继字符
        }
        else
        {
            /* 指针回退，重新开始 */
            i = i-j+1;
            j = 0;
        }
    }//while
    if(j > length2)return i-length2;
    else return 0;
}

/* KMP算法 */
int index_kmp(char *str1, char *str2,int pos)
{
    int i = pos;
    int j = 1;
    int next[255];
    get_next(str2,next);
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    while(i <= length1 || j <= length2)
    {
        if(j == 0 || str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j > length2)
    {
        printf("匹配成功！位置为：%d\n",i-length2);
    }
    else
    {
        printf("匹配不成功！\n");
    }
}

void get_next(char *str, int *next)
{
    int i = 0;
    int j = 0;
    next[1] = 0;
    int length = strlen(str);
    while (i< length)
    {
        if(j == 0 || str[i] == str[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
}