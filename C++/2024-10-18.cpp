#include <iostream>
#include <vector>


using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n-2;i++){
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0?1:0;
                nums[i+2] = nums[i+2] == 0?1:0;
                count++;
            }
        }
        return nums[n-1] == 0 || nums[n-2] == 0 ? -1:count;
    }

    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        if(n>=2*k)
            return -1;
        int count = 0;
        for(int i = 0;i<n-k+1;i++){
            if(nums[i] == 0){
                int tmp = 0;
                while(tmp<k){
                    nums[i+tmp] = nums[i+tmp] == 0?1:0;
                    tmp++;
                }
                count++;
            }
        }
        while(k--){
            if(nums[n-k] == 0){
                return -1;
            }
        }
        return count;
    }
    bool isPalindrome(string s) {
        int l = 0,r= s.size()-1;
        while(l<r){
            if(!isdigit(s[l]) && !isalpha(s[l])){
                l++;
                continue;
            }
            if(!isdigit(s[r]) && !isalpha(s[r])){
                r--;
                continue;
            }
            if(isalpha(s[l])){
                if(s[l] != s[r] && s[l] != s[r] - 32 && s[l] != s[r] + 32)
                    return false;
            }
            else{
                if(s[l] != s[r])
                    return false;
            }
            
            r--,l++;
        }
        return true;
    }


    void reverse(string& s,int l,int r){
        while(l<r){
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
    string reverseStr(string& s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        while(r<n){ 
            r+=k;
            if(r-l <= n){
                reverse(s,l,r-1);
            }
            r+=k;
            l = r;
            if(l<=n+k && r>=n){
                reverse(s,l,n-1);
            }
            
            
        }
        return s;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {};
    string s = "abcdefg";
    int k =8;
    cout << so.reverseStr(s,k) << endl;
    cin.get();
}