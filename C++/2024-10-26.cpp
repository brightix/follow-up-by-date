#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        unordered_map<int,int> idx;
        for(int i = 0;i<n1;i++){
            idx[nums1[i]] = i;
        }
        vector<int> ans(n1,-1);
        stack<int> st;
        for(int i = nums2.size()-1;i>=0;i--){
            int x = nums2[i];
            if(!st.empty() && x >= st.top()){
                st.pop();
            }
            if(!st.empty() && idx.find(x)!=idx.end()){
                ans[idx[x]] = st.top();
            }
            st.push(x);
        }
        return ans;
    }
};

int main()
{
    Solution so;
    vector<int> nums1 = {2,4},nums2 = {1,2,3,4};
    so.nextGreaterElement(nums1,nums2);
}