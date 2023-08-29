#include "lists.h"

/**
 * reverse_listint - this reverses a linked list
 * @head: this is a pointer to the first node in the list
 *
 * Return: returns pointer to the first node inthe new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}
