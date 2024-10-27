#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }

        sort(nums.begin(),nums.end());
        int maxi = nums[n-1] > nums[0] ? nums[n-1] : nums[0];
        int mini = nums[n-1] < nums[0] ? nums[n-1] : nums[0];        
        for(int i = 0;i<n;i++){
            int big = nums[i] + k - maxi;
            int small = mini - (nums[i] - k);
            if(big > small){//如果当前数字加k的影响大于减k,就和最小值比
                mini = min(mini,nums[i]-k);
            }
            else
                maxi = max(maxi,nums[i] + k);//4
        }
        return maxi - mini;
    }

    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int> cnt;
        int sec = n/4;
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            cnt[s[i]]++;
        }
        if(cnt['Q'] == sec && cnt['W'] == sec && cnt['E'] == sec && cnt['R'] == sec)
            return 0;
        for(int l = 0,r = 0;r<n;r++){
            --cnt[s[r]];
            while(cnt['Q'] <= sec && cnt['W'] <= sec && cnt['E'] <= sec && cnt['R'] <= sec){
                ans = min(ans,r-l+1);
                ++cnt[s[l++]];
            }
        }
        return ans;
    }

    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n-1;
        while(r && arr[r]>=arr[r-1])
            r--;
        if(r == 0) return 0;
        int ans = r;
        for(int l = 0;l == 0 || arr[l-1] <= arr[l] ;l++){
            while(r<n && arr[l] > arr[r])
                r++;
            ans = min(ans,r-l-1);
        }
        return ans;
    }
};

int main(){
    Solution so;
    vector<int> nums = {1,2,3,3,10,1,3,3,5};
    int k = 5;
    string s = "WWEQERQWQWWRWWERQWEQ";
    cout << so.findLengthOfShortestSubarray(nums);
}