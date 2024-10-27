#define fmax(a,b) ((a)>(b)?(a):(b))
#include <stdio.h>
#include <stdlib.h>

int rob(int* nums, int numsSize) {
    if(numsSize < 2){
        return nums[0];
    }
    else if(numsSize < 3){
        return fmax(nums[0],nums[1]);
    }
    int* dp1 = (int*)malloc(sizeof(int)*numsSize);
    dp1[0] = nums[0];
    dp1[1] = nums[1];
    int* dp2 = (int*)malloc(sizeof(int)*numsSize);
    dp2[numsSize-1] = nums[numsSize-1];
    dp2[numsSize-2] = fmax(nums[numsSize-2],nums[numsSize-1]);
    int max = fmax(fmax(dp1[0],dp1[1]),fmax(dp2[numsSize-2],dp2[numsSize-1]));
    for(int i = 2;i< numsSize - 1;i++){
        dp1[i] = fmax(nums[i]+dp1[i-2],dp1[i-1]);
        dp2[numsSize - i - 1] = fmax(nums[numsSize - i - 1] + dp2[numsSize - i + 1],dp2[numsSize - i]);
        int tmp = fmax(dp1[i],dp2[numsSize - 1 - i]);
        max = fmax(dp1[i],dp2[numsSize - i - 1]);
    }
    free(dp1),free(dp2);
    return max;
}

int main(){
    int nums[5] = {1,3,1,3,100};
    printf("%d",rob(nums,5));
    return 0;
}