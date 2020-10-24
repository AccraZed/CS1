#include <stdio.h>
#include <stdlib.h>

void twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;

    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize - 1; j++)
        {
            if (nums[i] + nums[j] == target)
                break;
        }
    }
    
    printf("%d %d", nums[i], nums[j]);
    
}