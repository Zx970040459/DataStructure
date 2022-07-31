#include <stdio.h>
#include <string.h>
int test()
{
    int count = 0;//定义计数器
    const char *list[4] = 
    {
        "aotraddfdfadfd","aotraldjsdf",
        "aotrawewes","aorapoods"
    };
    for(int i =0;i<4;i++)
    {
        if(strncmp(list[i],"aotra",5) == 0)
        {
            count++;
        }
    }
    printf("结果是：%d\n",count);
    return 1;
}
void test2()
{
    char str1[20] = "zhangzhang";
    char *str2 = "xuxiao";
    printf("拷贝结果是：%s\n",strncpy(str1,str2+3,2));
    //拷贝结果是：xuangzhang
}
void test3()
{
    char str1[100] = "拼接的内容：";
    char *str2 = "测试1的内容";
    sprintf(str1,"测试1:%s",str2);
    puts(str1);
}

void test4()
{
    char *str1 = "dadfasdaabbccddrr：";
    char *str2 = "aabbccddrr";
    if(strstr(str1,str2) != NULL)
    {
    printf("主串中找到子串！\n");
    }
    else
    {
        printf("未找到子串！\n");
    }
    //输出的结果为：主串中找到子串！
}
void test5()
{
    //查找换行符
    char *str1 = "ceshi\n";
    char *find = strchr(str1,'\0');
    if(find != NULL)
    printf("找到换行符！\n");
    else
    printf("未找到换行符！\n");
}
void test6()
{
    int a[10];
    memset(a,-1,sizeof(a));
    for(int i=0;i<10;i++)
    {
        printf("i = %d\t",i);
        printf("a = %d\n",a[i]);
    }
}
void test7()
{
    char a[10];
    memset(a,'1',sizeof(a));
    for(int i=0;i<10;i++)
    {
        printf("i = %d\t",i);
        printf("i = %c\n",a[i]);
    }
}
int main()
{
    test7();
    return 0;
}

