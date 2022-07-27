#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 用于临时测试算法与数据结构用 */
int Index_String(char *str1,char *str2);
int Get_Next(char *str,int *next);
int get_next(char *str,int *next);


int main()
{
	char *str1 = "MynamesasaasdasdasdIs Zhangxu dfdfdfsfasfasdfafasdfadsdfsdf";
	printf("The string1 lenght is->:%d\n",(int)strlen(str1));
	Index_String(str1,"Zhangxu");
	return 0;
}

/* KMP算法实现 */
/* next数组的求解 */
int Index_String(char *str1,char *str2)
{
	int i =0,j = 0;
	int next[255];
	get_next(str2,next);

	int length1 = (int)strlen(str1);
	int length2 = (int)strlen(str2);
	for(int a = 0; a<length2 ;a++)
	{
		printf("Next[%d] = %d\n",a,next[a]);
	}
	while(i< length1 && j < length2)
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
	}//while
	if(j >= length2)
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
	int length = (int)strlen(str);

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
/* 推荐记忆方法 */
int get_next(char *str,int *next)
{
	int i = 1,j = 0;
	next[0] = -1;
	next[1] = 0;
	int length = strlen(str);
	while (i <= length)
	{
		if(j == 0 || str[i] == str[j])
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
	return 1;
}