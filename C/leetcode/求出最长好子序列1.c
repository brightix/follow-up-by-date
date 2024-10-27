#include <stdio.h>

int maximumLenth(int* nums,const int numsSize,int k)
{
    int flag = 0;
    int retArr[10]={0};
    int ret=0;
    int i=0;
    int k =0;
    int final =0;
    while(ret<(numsSize/2))
    {
        ret=0;
        for(i=0;i<numsSize-1;i++)
        {

            if(nums[i]!=nums[i+1])
            {
                flag++;
                if(flag>k)
                    break;
            }
            ret++;
        }
        i++;
        retArr[k++]=ret;
    }
    k--;
    i=0,k=0;
    while(k--)
    {
        final=final>retArr[i]?final:retArr[i];
        i++;
    }
    return -1;
}

int main()
{
    int nums[10]={1,2,1,1,3};
    int k = 2;
    maximumLenth(nums,5,k);
    return 0;
}