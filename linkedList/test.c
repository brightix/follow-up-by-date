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
	LLPushBack(&list, 1);
	LLPushBack(&list, 2);
	LLPushBack(&list, 3);
	LLPushBack(&list, 4);
	LLPushBack(&list, 5);


	LLPrint(list);

	DestroyLL(&list);
}

int main()
{
	LLTest();
	return 0;
}