#include <stdio.h>
#include <stdlib.h>

#if __STDC_VERSION__!= 199901l
#error 
#endif

#define Bit3 (0x1<<2)
#define GetBits(Number,pos)  ((Number)>>(pos)&1) //查询某个数的某位的值
#define PR(...) printf(__VA_ARGS__) 
int main()
{
    int a = 0xaa;
    PR("a第2位的值为:%d\n",GetBits(a,2));
    a |= Bit3;
    PR("a右移动3位为:%d\n",a);
    PR("a第2位的值为:%d\n",GetBits(a,2));
    PR("%s\n",__DATE__);
    PR("%s\n",__TIME__);
    PR("%s\n",__FILE__); //显示当前文件名
    PR("%d\n",__LINE__); //显示当前行号
    PR("%d",__STDC_VERSION__);
    return 0;
}
 