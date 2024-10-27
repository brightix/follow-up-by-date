#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int cost = 0;
        int ans = 1;
        sort(nums.begin(),nums.end());
        for(int l = 0,r = 1;r<n;r++){
            if(nums[l]<nums[r]){
                cost+=(nums[r] - nums[l]) * (r-1);
                while(cost>k){
                    cost-=nums[r] - nums[l];
                    l++;
                }
                ans = max(ans,r-l+1);
            }
        }
        return ans;
    }   
    int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char,int> cnt = {{'a',0},{'b',0},{'c',0}};
        int i =0;
        int ans = INT_MAX;
        while(i < n && (cnt['a'] < k || cnt['b'] < k || cnt['c'] < k)){
            cnt[s[i++]]++;
        }
        if(i > n)
            return -1;
        else{
            ans = i;
        }
        int j = n-1;
        i--;
        while(i>=0){
            cnt[s[i]]--;
            
            while(j >= 0 && (cnt['a'] < k || cnt['b'] < k || cnt['c'] < k)){
                cnt[s[j--]]++;
            }
            ans = min(ans,n-1-j+i);
            i--;
        }
        return ans;
    }
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> cnt;
        int n = s.size();
        string tmp = s.substr(0,k-1);
        for(int i = k - 1;i<n;i++){
            tmp.push_back(s[i]);
            cnt[tmp]++;
            tmp.erase(0,1);
        }
        if(cnt.size() == pow(2,k))
            return true;
        else
            return false;
    }

        bool hasAllCodes2(string s, int k) {
        unordered_set<string> exists;
        int n = s.size();
        for(int i = 0;i+k<=n;i++){
            exists.insert(move(s.substr(i,k)));
        }
        return exists.size() == pow(2,k);
    }



    void reverse(string& s,int l,int r){
        while(l<r){
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++,r--;
        }
    }
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        while(r<n){
            while(r<n && s[r] != ' ')r++;
            reverse(s,l,r-1);
            l = ++r;
        }
        return s;
    }
};

int main(){
    Solution so;
    vector<int> nums = {9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    string s = "Let's take LeetCode contest";
    string binS = "00110";
    int k = 2;
    cout << so.reverseWords(s) << endl;
    cin.get();
}