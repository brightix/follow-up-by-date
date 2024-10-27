#include <iostream>
#include <string>
#include <cmath>
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int n = std::to_string(num).size();
        long long remainder = pow(10,k);
        int ans = 0;
        for(int i = n-k;i>=0;i--){
            int divisor = pow(10,i);
            int tmp = num/divisor%remainder;
            if(tmp == 0)
                continue;
            int a = num%((num/divisor)%remainder);
            if(a == 0)
                ans++;
        }
        return ans;
    }
};

int main()
{
    Solution so;
    so.divisorSubstrings(1000000000,10);
    std::cin.get();
}