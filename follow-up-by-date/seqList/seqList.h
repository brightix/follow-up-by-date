#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef  int SLDataType;


typedef struct seqList
{
    SLDataType* data;
    int size;
    int capacity;
}SL;

void SeqListInit(SL* PL);//初始化顺序表
void seqListCheck(SL* PL);//扩容
void seqListPushBack(SL* PL, SLDataType n);//尾插入
void seqListPopBack(SL* PL);//尾删除
void seqListPushFront(SL* PL, SLDataType n);//头插入
void seqListPopFront(SL* PL);//头删除
int  seqListSearch(SL* PL,SLDataType n);//查找
void seqListInsertion(SL* PL, int pos, SLDataType n);//指定位置插入
void seqListErase(SL* PL, int pos);
void destroySeqList(SL* PL);//释放顺序表
