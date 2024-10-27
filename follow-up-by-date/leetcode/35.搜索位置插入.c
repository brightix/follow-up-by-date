#include <stdio.h>

//35.搜索位置插入

int searchInsert2(int* nums, int numsSize, int target) //优化后的
{
    int start = 0, end = numsSize - 1;
    int m =0;
    while(start<=end)
    {
        m=start+(end-start)/2;
        if(nums[m]==target)
        {
            return m;
        }
        if(nums[m]>target)
            end = m -1;
        if(nums[m]<target)
            start=m+1;
    }
    return start;
}

int searchInsert(int* nums, int numsSize, int target) {
    int start = 0, end = numsSize - 1;
    int m = 0;
    int mid = 0;
    if (target < nums[0])
        return 0;
    if (target > nums[numsSize - 1])
        return numsSize;
    while (1) {
        m = (start + end) / 2;
        if (target == nums[m]) {
            return m;
        } else if (target > nums[m]) {
            if (target <= nums[m + 1]) {
                return m + 1;
            }
            start = m;
        } else if (target < nums[m]) {
            if (target > nums[m - 1]) {
                return m;
            }
            end = m;
        }
    }
}

int main()
{
    int nums[4] = {1,3,5,6};
    printf("%d",searchInsert(nums,4,5));
    return 0;
}