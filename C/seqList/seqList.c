#include "seqList.h"

void SeqListInit(SL* PL)
{
    PL->data     = NULL;
    PL->size     = 0;
    PL->capacity = 0;
}
void seqListCheck(SL* PL)
{
    if (PL->size == PL->capacity)
    {
        int newCapacity = PL->capacity == 0 ? 5 : PL->capacity * 2;
        SLDataType* ptr = (SLDataType*)realloc(PL->data, newCapacity * sizeof(SLDataType));
        if (ptr == NULL)
        {
            printf("扩容失败！\n");
            exit(-1);
        }
        PL->data = ptr;
        PL->capacity = newCapacity;
    }
}
void seqListPushBack(SL* PL, SLDataType n)
{
    seqListInsertion(PL, PL->size, n);
}
void seqListPopBack(SL* PL)
{
    if (PL->size == 0)
    {
        printf("已经没有东西可以删了！！\n");
        return;
    }
    seqListErase(PL, PL->size-1);
}
void seqListPushFront(SL* PL, SLDataType n)
{
    seqListInsertion(PL, 0, n);
}
void seqListPopFront(SL* PL)
{
    int i; 
    if (PL->size == 0)
    {
        printf("已经没有东西可以删了！！\n");
        return;
    }
    seqListErase(PL,0);
}
int seqListSearch(const SL* PL,SLDataType n)
{
    assert(PL);
    int i=0;
    for(i = 0; i < PL->size; i++)
    {
        if (PL->data[i] == n)
        {
            return i;
        }
    }
    return -1;
}
void seqListInsertion(SL* PL, int pos, SLDataType n)
{
    if (PL == NULL)
    {
        printf("传入的指针型参数为空指针！");
        return;
    }
    assert(pos <= PL->size && pos >= 0);
    seqListCheck(PL);
    int i = 0;
    for (i = PL->size; i > pos; i--)
    {
        PL->data[i] = PL->data[i - 1];
    }
    PL->data[i] = n;
    PL->size++;
}
void seqListErase(SL* PL, int pos)
{
    if (PL == NULL)
    {
        printf("传入的指针型参数为空指针！");
        return;
    }
    assert(pos >= 0 && pos < PL->size);
    int i;
    for (i = pos; i < PL->size-1; i++)
    {
        PL->data[i] = PL->data[i + 1];
    }
    PL->size--;
}
void destroySeqList(SL* PL)
{
    if (PL !=NULL)
    {
        free(PL->data);
        PL->data = NULL;
        PL->size = 0;
        PL->capacity = 0;
    }
}
