#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        for(int l = 0,r = 0;r<n;r++){
            sum+=nums[r];
            while(sum*(r-l+1)>=k){
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};
int main()
{
    Solution so;
    vector<int> nums = {2,1,4,3,5};
    int k = 10;
    cout << so.countSubarrays(nums,k);
}