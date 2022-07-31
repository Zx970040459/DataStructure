#include <stdio.h>
#include <stdlib.h>
int lengthOfLongestSubstring(char * s)
{
    int index[128] = {0};
    int start = 0,length = 0,max = 0;
    /* ①遍历字符串 */
    for(int i=0;s[i]!='\0';i++)
    {
        /* 如果字母不是第一次出现 */
        if(index[s[i]] > start)
        {
            length = i - start;
            start = index[s[i]];
            if(length > max)
            {
                max = length;
            }
        }
        index[s[i]] = i+1;
    }
    length = sizeof(s);
    if(length - start > max)
        return length-start;
    else
        return max;
}

int main()
{
    return 0;
}