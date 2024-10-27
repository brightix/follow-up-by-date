#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
long long countGood(vector<int> &nums, int k) {
        unordered_map<int, int> cnt;
        long ans = 0;
        int left = 0, pairs = 0;
        for (int x : nums) {
            pairs += cnt[x]++; // 移入右端点
            while (pairs - cnt[nums[left]] + 1 >= k)
                pairs -= --cnt[nums[left++]]; // 移出左端点
            if (pairs >= k) ans += left + 1;
        }
        return ans;
}

string minWindow(string s, string t) {
        unordered_map<char,int> word;
        unordered_map<char,int> str;
        int ans = INT_MAX;
        int n = s.size();
        string ret;
        for(char c : t){
            word[c]++;
        }
        for(int l = 0,r = 0;r<n;r++){
            str[s[r]]++;
            while(str[s[r]]>word[s[r]]){
                if(!(--str[s[l]])){
                    str.erase(s[l]);
                }
                l++;
            }
            if(ans>r-l+1){
                ans = r-l+1;
                ret = s.substr(l,r-l+1);
            }
        }
    return ret;
}

int findWinningPlayer(vector<int>& skills, int k) {
        queue<int> queue;
        int n = skills.size();
        for(int i = 0;i<n;i++){//选手入队
            queue.push(i);
        }
        int king = queue.front();//第一个选手为擂主
        int table = 0;//战绩表
        queue.pop();
        while(table<k){//擂主双杀就返回king下标
            int cur = queue.front();//挑战者参赛
            queue.pop();
            if(skills[king] > skills[cur]){//冠军卫冕
                table++;
                queue.push(cur);
            }
            else{                   //冠军被取代
                queue.push(king);
                king = cur;
                table = 1;
            }
        }
        return king;
}

int main()
{
    vector<int> skills = {16,4,7,17};
    
    vector<int> nums = {3,1,4,3,2,2,4};
    int k = 2;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    minWindow(s,t);
}