#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int i=0,j=1;
    while(j<numsSize)
    {
        if(nums[i]^nums[j]!=0)
        {
            nums[++i]=nums[j]; 
        }
        j++;
    }
    return i+1;
}
int main()
{
    int nums[10]={0,0,1,1,1,2,2,3,3,4};
    int numsSize=10;
    int i=0;
    int ret = removeDuplicates(nums,numsSize);
    for(i=0;i<ret;i++)
    {
            printf("%d ",nums[i]);
    }

}