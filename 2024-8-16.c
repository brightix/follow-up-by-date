#include <stdio.h>

//时间复杂度为 O(N),空间复杂度为O(1)

void reverse(int* arr,int left,int right)
{
    while(left<right)
    {
        /*           int temp =arr[left];
        arr[left]=arr[right];
        arr[right]= temp;     
*/
        arr[left]=arr[left]^arr[right];
        arr[right]=arr[left]^arr[right];
        arr[left]=arr[left]^arr[right];

        left++,right--;
    }
}

void rotate(int* arr,int numsSize,int k)
{
    k%=numsSize;
    reverse(arr,0,numsSize-k-1);
    reverse(arr,numsSize-k,numsSize-1);
    reverse(arr,0,numsSize-1);
}

int main()
{
    int i;
    int arr[10]={4,5,6,7,8,9,0,1,2,3};
    for(i=0;i<10;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    rotate(arr,10,99);
    for(i=0;i<10;i++)
    {
        printf("%d",arr[i]);
    }
    
    return 0;
}