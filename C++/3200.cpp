#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

void addLine(int& balls,int& lineCount,int& ans,int& flag)
{
    if(balls<lineCount || balls == 0)
    {
        flag = 0;
        return;
    }
    ans++;
    balls -=lineCount;
    lineCount++;
}
using namespace std;
class Solution {
public:
    
    int maxHeightOfTriangle(int red, int blue) {
        int flag = 1;
        int ans1 = 0,ans2 = 0;
        int lineCount1 = 1;
        int lineCount2 = 1;
        int red_ = red;
        int blue_ = blue;
        while(flag)
        {
            addLine(red_,lineCount1,ans1,flag);
            if(!flag)
                break;
            addLine(blue_,lineCount1,ans1,flag);
        }
        flag = 1;
        while(flag)
        {
            addLine(blue,lineCount2,ans2,flag);
                        if(!flag)
                break;
            addLine(red,lineCount2,ans2,flag);
        }
        return ans1>ans2?ans1:ans2;
    }

        long long maximumSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> cnt;
        int sum = 0;
        int max = 0;
        for(int i =0;i<k-1;i++){
            sum+=nums[i];
            cnt[nums[i]]++;
        }
        int n = nums.size();
        for(int i = k - 1;i<n;i++){
            sum+=nums[i];
            
            cnt[nums[i]]++;
            if(cnt.size() == k)
                max = max>sum?max:sum;
            if(--cnt[nums[i+1-k]]==0)
            {
                cnt.erase(nums[i+1-k]);
            }
            sum-=nums[i+1-k];
        }
        return max;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = accumulate(nums.begin(),nums.end(),0);
        if (cnt == 0)
            return 0;
        int cur = 0;
        for (int i = 0; i < cnt; i++) {
            cur += (1 - nums[i]);
        }
        int ans = cur;
        for (int i = 1; i < n; i++) {
            if(nums[i-1] == 0){
                --cur;
            }
            if(nums[(i+cnt-1)%n] == 0){
                ++cur;
            }
            ans = min(ans,cur);
        }
        return ans;
    }
};


int main()
{
    std::vector<int>nums = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    int k = 3;
    Solution so;
    std::cout << so.minSwaps(nums) << std::endl;

    std::cin.get();
}