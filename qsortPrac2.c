#include <stdio.h>

int intCmp(const void* p1,const void* p2)
{
    return *(int*)p1-*(int*)p2;
}

void Swap(char* parr1,char* parr2,int width)
{
    int i;
    char temp=0;
    for(i=0;i<width;i++)
    {
        temp=*parr1;
        *parr1=*parr2;
        *parr2=temp;
        parr1++,parr2++;
    }
}
void MyQsort(void* base,int sz,size_t width,int(*cmp)(const void* p1,const void* p2))
{
    int i,j;
    for(i=0;i<sz-1;i++)
    {
        int flag=1;
        for(j=0;j<sz-1;j++)
        {
            if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
            {
                Swap(((char*)base)+j*width,((char*)base)+(j+1)*width,width);
            }
            flag=0;           
        }
        if(flag)
            break;
    }
}

void displayArr(int* parr,int sz)
{
    int i,j;
    for(i=0;i<sz;i++)
    {
        printf("%d ",parr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10]={10,1,9,2,8,3,7,4,6,5};
    int sz=sizeof(arr)/sizeof(arr[0]);
    displayArr(arr,sz);
    MyQsort(arr,sz,sizeof(arr[0]),intCmp);
    displayArr(arr,sz);
    return 0;
}