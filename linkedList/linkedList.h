#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int LLDataType;

typedef struct linkList
{
	LLDataType data;
	struct linkList* next;
}LLNode;

//void initLL();

void LLPushBack(LLNode** pplist,LLDataType x);
void DestroyLL(LLNode** pplist);