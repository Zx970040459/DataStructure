#include <stdio.h>

/* 
    电机堵转检测接口函数编写
    给定AD采集接口函数：
 */

int get_adc_value();

int Motor_Test()
{
    int state = 0;
    int data[15] = {10,10,100,10,10,100,10,10,10,300,200,200,200,100,100};
    // for(int i=0;i<15;i++)
    // {
    //     int a = get_adc_value();
    //     data[i] = a;
    //      delay(10);//延时10ms
    // }
    for(int i=0;i<15;i++)
    {
        if(data[i]>280 || data[i]<30)
            state++;
        else break;
    }
    if(state >= 5)
    {
        printf("电机堵转!\n");
        return -1;
    }
    else
    {
        printf("电机工作正常!\n");
        return 0;
    } 
}

int main()
{
    Motor_Test();
    return 0;
}