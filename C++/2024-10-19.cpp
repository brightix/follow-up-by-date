#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>


using namespace std;
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        map<int,int> cnt;
        int n = nums.size();
        for(int i = 0;i<k-1;i++){
            cnt[nums[i]]++;
        }
        for(int i = k-1;i<n;i++){
            cnt[nums[i]]++;
            for(int i = 0;i<k;i++){
                
            }




            if(cnt.rbegin()->second > x){//最后一个元素有两个以上
                if(cnt.rbegin()->first < 0)
                    ans.push_back(cnt.rbegin()->first);
                else
                    ans.push_back(0);
            }
            else{
                auto it = cnt.end();
                advance(it, -2);
                if(it->first < 0)
                    ans.push_back(it->first);
                else
                    ans.push_back(0);
            }


            if(!--cnt[nums[i-k+1]])//头删
                cnt.erase(nums[i-k+1]);
        }
        return ans;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int ans = INT_MAX;
        for(int l = 0,r = 0;r<n;r++){
            cur+=nums[r];
            while(cur>target){
                cur-=nums[l];
                l++;
            }
            ans = min(ans,r-l+1);
        }
        return cur == target ? ans:0;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {2,3,1,2,4,3};
    int k = 2;
    int x = 2;
    int target = 7;
    so.minSubArrayLen(target,nums);
    cin.get();
}