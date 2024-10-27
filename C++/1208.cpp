#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int cost = 0;
        int i = 0, j = 0;
        while(j<n){
            int cur = abs(s[j]-t[j]);
            cost+= cur;
            while(cost>maxCost){
                cost -= abs(s[i]-t[i]);
                i++;
            }
            if(cost<=maxCost){
                ans = max(ans,j - i + 1);
                j++;
            }
        }
        return ans;
    }

        int longestSemiRepetitiveSubstring_(string s) {
        int n = s.size();
        int cnt[10]{};
        int i = 0;
        int j = 0;
        int ans = 0;
        int flag = 0;
        int pose = 0;
        while(j<n){
            cnt[s[j] - '0']++;
            if(cnt[s[j] - '0'] > 1){
                flag++;
                if(flag == 1)
                    pose = j;
                if(flag > 1){
                    for(int k = i;k<pose;k++){
                        cnt[s[k]-'0']--;
                    }
                    i = pose;
                    pose = j;
                    flag--;
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int flag = 0;
        int i = 0,j = 1;
        int pose = 0;
        while(j<n){
            if(s[j] == s[j-1]){
                flag++;
            }
            while(flag > 1){
                if(s[i] == s[i+1])
                    flag--;
                i++;
            }
            j++;
            ans = ans> j-i ? ans : j-i;
        }
        return ans;
    }
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> fruitsCount;
        int ans = 0;

        int left = 0;
        for(int right = 0;right<n;right++){
            fruitsCount[fruits[right]]++;
            while(fruitsCount.size()>2){
                fruitsCount[fruits[left]]--;
                if(fruitsCount[fruits[left]] == 0){
                    fruitsCount.erase(fruits[left]);
                }
                left++;
            }
            ans = ans > right - left + 1?ans:right - left + 1;
        }
        return ans;
    }

        int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int tmp = 0;
        unordered_map<int ,int> cnt;
        for(int r = 0;r<n;r++){
            cnt[nums[r]]++;
            tmp+=nums[r];
            while(cnt.size() < r - l + 1){
                cnt[nums[l]]--;
                tmp-=nums[l];
                if(cnt[nums[l]] == 0){
                    cnt.erase(nums[l]);
                }
                l++;
            }
            ans = max(ans,tmp);
        }
        return ans;
    }

        int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        unordered_map<int,int> cnt;
        int ans = 0;
        for(int r = 0 ; r < n ; r++){
            cnt[nums[r]]++;
            while(cnt[nums[r]] > k){
                cnt[nums[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }

        int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1;
        int cur = 1;
        int max_ = nums[1];
        int min_ = nums[0];
        for(int r = 2,l = 0;r<n;r++){
            cur++;
            while(nums[r] < nums[min_] + k || nums[r] > nums[max_] - k){
                l++;
                cur--;
            }
            min_ = l;
            ans = max(ans,cur);
        }
        return ans;
    }

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tmp = 0;
        int l = 0,r = n-1;
        int ans = INT_MAX;
        while(l < n && tmp + nums[l] <= x){
            tmp += nums[l];
            if(tmp == x)
                ans = min(ans,l+1);
            l++;
        }
        int count = l--;
        while(r > l && tmp + nums[r] <=x){
            tmp+=nums[r];
            count++;
            if(tmp == x)
                ans = min(ans,count);
            r--;
        }
        while(l>=0){
            count--;
            tmp-=nums[l];
            while(r > l && tmp + nums[r] <=x){
                tmp+=nums[r];
                count++;
                if(tmp == x)
                    ans = min(ans,count);
                r--;
            }
            l--;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution so;
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    string s1 = "0001";
    vector<int> fruits = {1,2,3,2,2};
    vector<int> nums = {3,2,20,1,1,3};
    int k = 10;
    cout << so.minOperations(nums,k) << endl;
    std::cin.get();
}