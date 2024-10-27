#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int LLDataType;

typedef struct linkList
{
	LLDataType data;
	struct linkList* next;
}LLNode;

//void initLL();

void LLPushBack(LLNode** pphead,LLDataType x);
void LLPushFront(LLNode** pphead, LLDataType x);
void LLPopBack(LLNode** pphead);
void LLPopFront(LLNode** pphead);
void DestroyLL(LLNode** pphead);