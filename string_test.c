#include "string_test.h"

/* 暴力BF匹配算法 */
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
void get_next(char s[],int next[])
{	
	int len=0;
    int i=0;
    int j=-1;
    next[0]=-1;
    len=strlen(s);
    while(i<len-1)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
			next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int strStr(char * haystack, char * needle){
    int i=0;
    int j=0;
    int len1=strlen(haystack);
    int len2=strlen(needle);
    int *next = (int*)malloc(sizeof(int)*len2);
    get_next(needle,next);
    while(i<len1 && j<len2)
    {
        if(j==-1 || haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>=len2)
        return i-len2;
    else
        return -1;
}
/* 反转字符串 */
void ReverseString(char *str)
{
    int length = strlen(str);
    int start = 0;
    int end = length -1;
    char temp;//临时交换区
    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void test_reverse(void){
    char str[] = "nimenhao";
    ReverseString(str);
    puts(str);
}
int main()
{
    test_reverse ();

    return 0;
}