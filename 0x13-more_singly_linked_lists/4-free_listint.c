#include "lists.h"

/**
 * free_listint - this fres a linked list
 * @head: listint_t lists to the freed list
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
