#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> arr;
        for(int i = 0;i<n;i++){
            int l = 0;
            int r = m;
            int power = spells[i];
            while(l<r){
                int mid = l+((r-l)>>1);
                if(power*potions[mid]<success){
                    l=mid + 1;
                }
                else{
                    r = mid;
                }
            }
            arr.push_back(m-l);
        }
        return arr;
    }
    int maxFrequence(string s){
        sort(s.begin(),s.end());
        int ret = 0;
        int i = 0;
        while(i == 0 || s[i]==s[i-1])ret++,i++;
        return ret;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> arr;
        vector<int> w;
        for(int i = 0;i<words.size();i++){
            w.push_back(maxFrequence(words[i]));
        }
        sort(w.begin(),w.end());
        for(int i = 0;i<queries.size();i++){
            int l = -1;
            int r = w.size();
            int cur = maxFrequence(queries[i]);
            while(l+1<r){
                int mid = l+((r-l)>>1);
                if(cur < w[mid]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            arr.push_back(w.size()-r);
        }
        return arr;
    }

    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        for (int j = 0; j < nums.size(); ++j) {
            auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]); // <= upper-nums[j] 的 nums[i] 的个数
            auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]); // < lower-nums[j] 的 nums[i] 的个数
            ans += r - l;
        }
        return ans;
    }
};

int main()
{
    Solution so;
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    long long success = 7;
    vector<string> queries = {"bbb","cc"};
    vector<string> words = {"a","aa","aaa","aaaa"};
    vector<int> nums = {0,1,7,4,4,5};
    int lower = 3;
    int upper = 6;
    so.countFairPairs(nums,lower,upper); 
}