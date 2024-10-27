#include <iostream>
#include <vector>

using namespace std;
int test(vector<int>& nums)
{
    int n = nums.size();
    int mx = nums[0];
    int tmp = mx;
    for(int l = 0,r = 1;r < n ;r++){
        tmp+=nums[r];
        while(l<r && tmp<mx)
    }
}

int main()
{
    vector<int> nums = {3,-4,2,-1,2,6,-5,4};
    cout << test(nums) << endl;
}