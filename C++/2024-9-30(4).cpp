#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int times = 0;
    int n = tickets[k]-1;
    for(int i = 0;i<n;i++)//循环k位置的票数-1
    {
        for(int k = 0;k<ticketsSize;k++)
        {
            if(tickets[k]!=0)
            {
                times++;
                tickets[k]--;
            }  
        }
    }
    for(int j = 0;j<k+1;j++){
        if(tickets[j] != 0 )
        {
            times++;
            tickets[j]--;
        }
    }
    return times;
}


#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long left = 100;
    long long right = 0;
    
    for(int i = 0;i<timeSize;i++){
        left = MIN(left,time[i]);
        right = MAX(right,time[i]);
    }
    right*=totalTrips;
    int min = right;
    while(left + 1<right){
        long long mid = left + (right - left)/2;
        long long tmp = 0;
        for(int i = 0;i< timeSize;i++){
            tmp+=mid/time[i];//2
            if(tmp>=totalTrips)
                break;
        }
        if(tmp<totalTrips){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return right;
}

bool check(long long x, int* time, int timeSize, int totalTrips) {
    long long sum = 0;
    for (int i = 0; i < timeSize; i++) {
        sum += x / time[i];
        if (sum >= totalTrips) {
            return true;
        }
    }
    return false;
}

long long minimumTime2(int* time, int timeSize, int totalTrips) {
    int min_t = 100000, max_t = 0;
    for (int i = 0; i < timeSize; i++) {
        min_t = MIN(min_t, time[i]);
        max_t = MAX(max_t, time[i]);
    }

    int avg = (totalTrips - 1) / timeSize + 1;
    // 循环不变量：check(left) 恒为 false
    long long left = (long long) min_t * avg - 1;
    // 循环不变量：check(right) 恒为 true
    long long right = MIN((long long) max_t * avg, (long long) min_t * totalTrips);

    // 开区间 (left, right) 不为空
    while (left + 1 < right) {
        long long mid = (left + right) / 2;
        if (check(mid, time, timeSize, totalTrips)) {
            // 缩小二分区间为 (left, mid)
            right = mid;
        } else {
            // 缩小二分区间为 (mid, right)
            left = mid;
        }
    }

    // 此时 left 等于 right-1
    // check(left) = false 且 check(right) = true，所以答案是 right
    return right; // 最小的 true
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* getAverages(int* nums, int numsSize, int k) {
    long long* ans = (long long*)malloc(numsSize*sizeof(long long));
    long long avg = 0;
    int divide = 2*k+1;
    if(k>=numsSize){
        for(int i = 0;i<numsSize;i++){
            ans[i] = -1;
        }
        return ans;
    }

    for(int i = 0;i<k;i++){
        ans[i] = -1;
    }
    for(int i = 0;i<divide;i++){
        avg+=nums[i];
    }
    ans[k] = avg/divide;   
    for(int j = k + 1;j<numsSize-k;j++){
        avg +=nums[j+k] - nums[j-k-1];
        ans[j] = avg/divide;
    }
    for(int i = numsSize-k;i<numsSize;i++){
        ans[i] = -1;
    }

    return ans;
}

int* decrypt(int* code, int codeSize, int k) {
    int* ans = (int*)malloc(sizeof(int)*codeSize);
    ans = (int*)memset(ans,0,codeSize*sizeof(int));
    if(k>0){
        for(int i = 0;i<codeSize;i++){
            for(int j = i;j<k+i;j++){
                if(j+1>=codeSize){
                    ans[i]+=code[j+1-codeSize];
                }
                else
                    ans[i]+=code[j+1];
            }
        }
    }
    else if(k<0){
        for(int i = 0;i<codeSize;i++){
            for(int j = i;j>i+k;j--){
                if(j-1<=-1){
                    ans[i]+=code[codeSize+j-1];
                }
                else
                    ans[i]+=code[j-1];
            }
        }
    }
    
    return ans;
}

int main(){
    int arr[4] = {9,3,10,5};
    int time[7] = {9,7,10,9,10,9,10};
    int nums[9] = {7,4,3,9,1,8,5,2,6};
    int code[4] = {2,4,9,3};
    decrypt(code,4,-2);
    //getAverages(nums,9,3);
    //printf("%d",);
    return 0;
}