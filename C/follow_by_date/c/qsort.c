#include <stdio.h>
#include <string.h>

//ʵ��qsort���ܵ�bubbleSort 

int cmpByInt(const void* p1,const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

void Swap(char* buf1,char* buf2,int width)
{
    char temp=0;
    int i;
    for(i=0;i<width;i++)
    {
        temp=*buf1;
        *buf1=*buf2;
        *buf2=temp;
        buf1++;
        buf2++;
    }
}

void bubbleSort(void* base,unsigned int sz,unsigned int width,int(*cmp)(const void* p1,const void* p2))
{
    int i;
    //����
    for(i=0;i<sz-1;i++)
    {
        int j;
        int flag = 1;//���赱ǰΪ����˳��
        for(j=0;j<sz-1;j++)
        {
            if(cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)//����ȽϽ������0���򽻻�Ԫ������
            {
                Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
            }
            flag=0;
        }
        if(flag==1)
            break;
    }
}


int main()
{
    int i;
	int arr[10]={2,854,23,7,45,1,876,45,0,63};
    int sz=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
	bubbleSort(arr,sz,sizeof(arr[0]),cmpByInt);
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}