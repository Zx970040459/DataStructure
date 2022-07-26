#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 用于临时测试算法与数据结构用 */
int Index_String(char *str1,char *str2);
int Get_Next(char *str,int *next);

int main()
{
	Index_String("MynameIsZhangxu","Zhangxu");
	return 0;
}

/* KMP算法实现 */
/* next数组的求解 */
int Index_String(char *str1,char *str2)
{
	int i =1,j = 1;
	int next[255];
	Get_Next(str2,next);
	int length1 = strlen(str1);
	int length2 = strlen(str2);
	
	while(i<= length1 || j <= length2)
	{
		if(j == 0 || str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}//while
	if(j > length2)
	{
		printf("字符串匹配！位置序号为->  %d\n",i - length2);
		return 1;
	}
	else
	{
		printf("字符串不匹配！\n");
		return 0;
	}
}
int Get_Next(char *str,int *next)
{
	int i = 0;
	int j = 0;
	next[1] = 0;
	int length = strlen(str);

	while(i < length)
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
	return 1;
}
