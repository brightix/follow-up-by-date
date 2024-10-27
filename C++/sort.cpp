#include <iostream>
#include <vector>

class Sort{
private:
    int binarySearch(std::vector<int> nums,int r,int value)//找到插入位置,完全没必要...
    {
        int l = 0;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(value < nums[mid])
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
    void merge(std::vector<int>& nums,int l,int m,int r)
    {
        std::vector<int> tmp(r-l+1);
        int k = 0;
        int i = l,j = m+1;
        while(i<=m && j <=r){
            tmp[k++] = nums[i]<nums[j] ? nums[i++] : nums[j++];
        }
        while(i<=m)
        {
            tmp[k++] = nums[i++];
        }
        while(j<=r)
        {
            tmp[k++] = nums[j++];
        }
        int n = tmp.size();
        for(int p = 0;p<n;p++)
        {
            nums[l+p] = tmp[p];
        }
    }
public:
    void insertSort(std::vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
            int location = binarySearch(nums,i,nums[i]);//交换起点
            int var = nums[i];//代交换的值
            
            for(int j = i;j>location;j--)
            {
                nums[j] = nums[j-1];
            }
            nums[location] = var;
        }
    }
    
    void mergeSort(std::vector<int>& nums,int l,int r)
    {
        if(l>=r) return;
        int m = l+(r-l)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,r);
        merge(nums,l,m,r);
    }
};
int main()
{
    std::vector<int> nums = {2,4,6,3,1,5,9,9,9,25,14,28,9452,1221,52,7,2,5,0,};
    std::vector<int> nums1 = {5,3,6,2,1,4,9};
    Sort sort;
    sort.mergeSort(nums1,0,nums1.size()-1);
    for(int i = 0;i<nums1.size();i++){
        std::cout << nums1[i] << " ";
    }
    //sort.binarySearch(nums1,nums1.size(),3);
    std::cin.get();
}