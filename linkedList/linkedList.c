#include "linkedList.h"


void LLPushBack(LLNode** pphead, LLDataType x)
{
	LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
	if (newNode == NULL)
	{
		printf("Î²²åÊ§°Ü£¡\n");
		return;
	}
	newNode->data = x;
	newNode->next = NULL;

	
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		LLNode* tail = *pphead;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void DestroyLL(LLNode** pphead)
{
	if ((*pphead) != NULL)
	{
		free((*pphead));
		(*pphead) = NULL;
	}
}