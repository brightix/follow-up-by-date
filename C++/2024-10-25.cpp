#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = 1,r = accumulate(weights.begin(),weights.end(),0);
        auto check = [&](int mid) ->bool{
            int cost = 0;
            int i = 0;
            while(i<n){
                int contain = 0;
                while(i < n && contain+weights[i] <= mid){
                    contain+=weights[i];
                    i++;
                }
                cost++;
                if(cost > days)
                    return false;
            }
            return true;
        };
        while(l+1<r){
            int mid = l+(r-l)/2;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r = 10000;
        int n = piles.size();
        auto check = [&](int speed){
            int cost = 0;
            int i = 0;
            while(i<n){
                cost += (piles[i++]-1)/speed + 1;
                if(cost>h) return false;
            }
            return true;
        };
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int l = 1,r = 1000;//*max_element(workerTimes.begin(),workerTimes.end());
        int n = workerTimes.size();
        auto check = [&](int second){
            int h = 0;
            for(int i = 0;i<n;i++){
                h+=(workerTimes[i]-1)/second + 1;
                if(h>mountainHeight){
                    return true;
                }
            }
            return false;
        };
        while(l<r){
            int mid = l+(r-l)/2;
            if(check(mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
    bool check(int r,int n,vector<int> houses,vector<int> heaters){
        int j = 0;
        int m = heaters.size()-1;
        for(int i = 0;i<n;i++){
            while(j<m && abs(heaters[j] - houses[i]) <= r){
                j++;
            }
            if(abs(heaters[j] - houses[i]) > r)
                return false;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        int left = 0,right = max(houses.back(),heaters.back());
        while(left<right){
            int mid = left+(right-left)/2;
            if(check(mid,n,houses,heaters)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }

    bool checkPerfectNumber(int num) {
        //int n = num;//18
        int sum = 1;
        for(int i = 2;i*i<num;i++){
            int tmp = num/i;
            if(!(num%i)){
                if(tmp!=i)
                    sum+=i+tmp;//1+2+14+4+7
                else
                    sum+=i;
            }
        }
        return sum == num;
    }
};

int main()
{
    Solution so;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    vector<int> piles = {3,6,7,11};
    int mountainHeight = 4;
    vector<int>workerTimes = {2,1,1};
    int h = 8;
    int days = 5;
    vector<int> houses = {1,1,1,1,1,1,999,999,999,999,999}, heaters = {499,500,501};
    cout << so.checkPerfectNumber(28);

}