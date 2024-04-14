#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 *               using the Jump search algorithm.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: The first node in the skip list where the value is located,
 *         or NULL if the value is not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list;

    if (list == NULL) {
        return NULL;
    }

    while (current->express != NULL && current->express->n < value) {
        printf("Value checked at index [%lu] = [%d]\n",
               current->express->index, current->express->n);
        current = current->express;
    }

    while (current != NULL && current->n < value) {
        printf("Value checked at index [%lu] = [%d]\n",
               current->index, current->n);
        current = current->next;
    }

    if (current != NULL && current->n == value) {
        return current;
    }

    return NULL;
}
