#include "linkedList.h"

void LLPrint(const LLNode* pphead)
{
	LLNode* cur = pphead;
	if (cur == NULL)
	{
		printf("¸ÃÖ¸ÕëÎª¿Õ£¡\n");
		return;
	}
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void LLTest(void)
{
	LLNode* list= NULL;
	//LLPushBack(&list, 1);
	//LLPushBack(&list, 2);
	//LLPushBack(&list, 3);
	//LLPushBack(&list, 4);
	//LLPushBack(&list, 5);
	LLPushFront(&list, 1);
	LLPushFront(&list, 2);
	LLPushFront(&list, 3);
	LLPushFront(&list, 4);
	LLPushFront(&list, 5);
	//LLPopBack(&list);
	//LLPopBack(&list);

	LLPopFront(&list);
	LLPopFront(&list);


	LLPrint(list);

	DestroyLL(&list);
}

int main()
{
	LLTest();
	return 0;
}