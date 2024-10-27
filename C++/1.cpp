#include <stdio.h>

int maximumCount(int* nums, int numsSize){
    int left = 0;
    int right = numsSize -1;
    while(left<right){
        int mid = left + (right-left >>1);
        if(nums[mid]<0){
            left = mid+1;
        }
        else if(nums[mid]>0){
            right = mid;
        }
        else{
            left = mid;
            right = mid;
            while(left>=0 && nums[left] == 0){
                left--;
            }
            while(right<=numsSize-1 && nums[right] == 0){
                right++;
            }
            return left+1>numsSize-right-1?left+1:numsSize-right;
        }
    }
    return left>numsSize-right?left:numsSize - right;
}

int main(){
    int nums[3] = {-2,-2,-1};
    printf("%d",maximumCount(nums,3));
    return 0;
}