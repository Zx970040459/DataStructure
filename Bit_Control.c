/* C语言位操作学习 */
#include <stdio.h>
#include <stdlib.h>

#define BIT3 (0x1<<3) //注意括号！！！
int setBits(int data);
int clearBits(int data);
int main()
{
    printf("设置位3为1后的结果为：%x\n",setBits(0x5a));
    printf("清除位3为0后的结果为：%x\n",clearBits(0x5a));
    return 0;
}

int setBits(int data)
{
    data |= BIT3;
    return data;
}
int clearBits(int data)
{
    data &=~ BIT3;
    return data;
}