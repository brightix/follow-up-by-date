#include <iostream>
#include <vector>
#include <unordered_map>

#include <algorithm>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int ans = INT_MAX;
        for(int l = 0,r = 0;r<n;r++){
            cur+=nums[r];
            while(cur - nums[l] >=target){
                cur-=nums[l];
                l++;
            }
            if(cur >= target)
                ans = min(ans,r-l+1);
        }
        return ans == INT_MAX ? 0:ans;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> cnt(2,0);
        int minimal = INT_MAX;
        int ans_l = 0;
        for(int l = 0,r = 0;r<n;r++){
            cnt[s[r] - '0']++;
            while(cnt[1] > k || s[l] == '0'){
                cnt[s[l]- '0']--;
                l++;
            }
            if(cnt[1] == k){
                if(r-l+1 == minimal){
                    if(s.substr(ans_l,minimal) > s.substr(l,r-l+1)){
                        ans_l = l;
                        minimal = r-l + 1;
                    }
                }
                else if(r-l+1 < minimal)
                    ans_l = l,minimal = r-l + 1;
            }
        }
        return minimal != INT_MAX ? s.substr(ans_l,minimal) :"";
    }

    int minSizeSubarray(vector<int>& nums, int target) {
        int tmp = 0;
        int i = 0;
        int n = nums.size();
        while(tmp<target){
            tmp+=nums[i++ % n];
        }
        int k = i/n;
        int ans = INT_MAX;
        int sum = 0;
        for(int l = 0,r = 0;r<(k+2)*n;r++){
            sum+=nums[r%n];
            while(sum>target){
                sum-=nums[l%n];
                l++;
            }
            if(sum == target){
                ans = min(ans,r-l+1);
            }
        }
        return ans == INT_MAX ? -1:ans;
    }
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int> cnt;
        for(char word : s){
            switch(word){
                case 'Q':cnt[word]++;
                    break;
                case 'W':cnt[word]++;
                    break;
                case 'E':cnt[word]++;
                    break;
                case 'R':cnt[word]++;
                    break;
            }
        }
        int minimal = INT_MIN;
        char key;
        for(const auto& pair : cnt){
            if(pair.second > minimal){
                minimal = pair.second;
                key = pair.first;
            }
        }
        int ans = INT_MAX;
        int check = 0;
        for(int l = 0,r = 0;r<n;r++){
            check+= s[r] == key? 1:0;
            while(check>cnt[key] - n/4){
                check -= s[l] == key? 1:0;
                l++;
            }
            if(check == cnt[key] - n/4)
                ans = min(ans,r-l);
        }
        return ans;
    }

        bool isPrime(int n){
        if(n<2)
            return false;
        else if(n<4)
            return true;
        for(int i = 5;i*i<n;i+=6){
            if(i%n == 0 && i%(n+2) == 0)
                return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> arr;
        int n = nums.size();
        for(int i = 0,j = n-1;i<n;i++){
            arr.push_back(nums[i][i]),arr.push_back(nums[i][j--]);
        }
        sort(arr.begin(),arr.end());
        for(int i = arr.size()-1;i>=0;i--){
            if(isPrime(arr[i]))
                return arr[i];
        }
        return -1;
    }
};

int main(){
    Solution so;
    int target = 4;

    //vector<int> nums = {1,1,1,2,3};
    string s = "WWEQERQWQWWRWWERQWEQ";
    int k = 3;
    vector<vector<int>> nums = {{1,2,3},{5,6,7},{9,10,11}};
    cout << so.isPrime(985);
    cout << so.diagonalPrime(nums);
}