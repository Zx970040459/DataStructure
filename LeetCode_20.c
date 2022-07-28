/* LeetCode第20题，括号匹配问题 */
#include <stdio.h>
#include <stdbool.h>
/* 括号匹配问题实现：栈 */
_Bool isValid(char *string)
{
    char stack[10000]; //初始化栈
    int top = -1;//定义栈顶指针
    int i = 0;//定义数组下标
    while (string[i] != '\0')
    {
        switch(string[i])
        {
            case '('://入栈
                top++;
                stack[top] = string[i];
                break;
            case '[':
                top++;
                stack[top] = string[i];
                break;
            case '{':
                top++;
                stack[top] = string[i];
                break;
            case ')':
                if(top == -1)return false;
                if(stack[top] == '(')top--;//出栈
                else return false;
                break;
            case ']':
                if(top == -1)return false;
                if(stack[top] == '[')top--;//出栈
                else return false;
                break;
            case '}':
                if(top == -1)return false;
                if(stack[top] == '{')top--;//出栈
                else return false;
                break;
            default:break;
        }//switch
        i++;
    }//while
    if(top != -1)
    {
        //printf("括号不匹配！\n");
        return false;
    }
    else
    {
        //printf("括号匹配！\n");
        return true;
    }
}
int main()
{
    char *str ="{}{}()[][][][][][]'[][][]]";
    if(isValid(str) == true)printf("括号匹配！\n");
    else printf("括号不匹配！\n");
    return 0;
}

