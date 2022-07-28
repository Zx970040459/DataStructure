/* LeetCode第一题：两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum
 */
#include <stdio.h>
#include <stdlib.h>
/* 方法①：暴力求解法 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int a,b;//定义两个变量，用于求和的两个变量
    int *result = NULL;//初始化返回值指针
    *returnSize = 2; //初始化返回数组容量
    for(a = 0;a<numsSize-1;a++)
    {
        for(b = a+1;b<numsSize;b++)
        {
            if(nums[a]+nums[b] == target)
            {
                result = (int*)malloc(sizeof(int)*2);
                result[0] = a;
                result[1] = b;
                return result;
            }
        }
    }
    return result;
}

int main()
{    
    return 0;
}