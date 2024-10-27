#include "seqList.h"


void print(SL* PL)
{
    int i = 0;
    for (i = 0; i < PL->size; i++)
    {
        printf("%3d ", PL->data[i]);
    }
    if (PL->size == 0)
        printf("表内无数据！");
    printf("\n");
}
void Test()
{
    SL list;
    SeqListInit(&list);
    seqListPushBack(&list, 1);
    seqListPushBack(&list, 2); 
    seqListPushBack(&list, 3); 
    seqListPushBack(&list, 4); 
    seqListPushBack(&list, 5);
    print(&list);
    seqListPushFront(&list, 1);
    seqListPushFront(&list, 2);
    seqListPushFront(&list, 3);
    seqListPushFront(&list, 4);
    seqListPushFront(&list, 5);
    //seqListPopFront(&list);
    print(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);
    seqListPopFront(&list);    seqListPopFront(&list);
    print(&list);
    print(&list);


    destroySeqList(&list);

}

int main()
{
    Test();
    return 0;
}