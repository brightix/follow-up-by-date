#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    long long maxSum(std::vector<int>& nums, int m, int k) {
        std::unordered_map<int,int> cnt;
        int sum = 0;
        long long ans = 0;
        for(int i = 0;i<k-1;i++){
            sum+=nums[i];
            cnt[nums[i]]++;
        }
        for(int i = k-1;i<nums.size();i++){
            cnt[nums[i]]++;
            sum+=nums[i];
            if(cnt.size()>=m){
                ans = ans>sum?ans:sum;
            }
            sum-=nums[i-k+1];
            if(cnt[nums[i-k+1]]>0){
                cnt.erase(nums[i-k+1]);
            }
        }
        return ans;
    }
};

int main(){
    std::vector<int> nums = {1,1,1,3};
    Solution so;
    int m = 2;
    int k = 2;
    int a = so.maxSum(nums,m,k);
    std::cout << a << std::endl;
    std::cin.get();
}