#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int sat = 0;

    for(int i = 0;i<customersSize;i++){
        if(i<minutes)
            sat += customers[i];
        else if(grumpy[i] == 0)
            sat += customers[i];
    }
    int max = sat;
    //sat为直接发动技能时的回报分
    for(int i = 0; i < customersSize - minutes; i++){
        if(grumpy[i] == 1)
            sat -=customers[i];
        if(grumpy[i+minutes] == 1)
            sat += customers[i+minutes];
        max = MAX(max,sat);
    }
    return max;
}

int* searchRange(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    int flag = 0;
    int* ans = (int*)malloc(2*sizeof(int));
    ans[0] = -1,ans[1] = -1;


    while(left<=right){
        int mid = left+ (right - left)/2;
        if(nums[mid] < target){
            left = mid +1;
        }
        else if(nums[mid]>target){
            right = mid;
        }
        else{
            flag = 1;
            left = mid;
            right = mid;
            while(left>=0 && nums[left] == target){
                left--;
            }
            while(right<=numsSize-1 && nums[right] == target){
                right++;
            }
            break;
        }
    }
    if(flag == 1)
        ans[0] = left+1,ans[1] = right-1;
    return ans;
}

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;
    while(left<=right){
        int mid = left+((right-left)>>1);
        if(nums[mid]<target){
             left = mid+1;
        }
        else if(nums[mid]>target){
            right = mid-1;
        }
        else
            return mid;
    }
    return -1;
}

int main(){
    int customers[8] = {2,6,6,9};
    int grumpy[8] =    {0,0,1,1},     minutes = 1;
    int nums[6] = {-1,0,3,5,9,12}, target = 9;
    printf("%d",maxSatisfied(customers,8,grumpy,4,minutes));
    printf("%d",searchRange(nums,6,target));
    printf("%d",search(nums,6,target));
    return 0;
}