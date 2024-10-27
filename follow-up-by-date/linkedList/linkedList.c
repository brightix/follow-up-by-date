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
void LLPushFront(LLNode** pphead, LLDataType x)
{
	LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
	if (newNode == NULL)
	{
		printf("Í·²åÈëÊ§°Ü£¡\n");
		return;
	}
	newNode->data = x;
	newNode->next = *pphead;
	*pphead = newNode;
}
void LLPopBack(LLNode** pphead)
{
	assert(pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		LLNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
void LLPopFront(LLNode** pphead)
{
	assert(pphead);
	if ((*pphead)->next == NULL)
	{
		free((*pphead));
		*pphead = NULL;
	}
	else
	{
		LLNode* head = (*pphead)->next;
		free((*pphead));
		*pphead = head;
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