#include "search_algos.h"
#include <math.h>
#include <stdio.h>

size_t min(size_t a, size_t b) {
    return (a < b) ? a : b;
}

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if the value is
 *         not present or the array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step, prev;

    if (array == NULL || size == 0) {
        return -1;
    }

    step = sqrt(size);
    prev = 0;

    while (array[min(step, size) - 1] < value) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }

    while (array[prev] < value) {
        prev++;
        if (prev == min(step, size)) {
            return -1;
        }
    }

    if (array[prev] == value) {
        return prev;
    }

    return -1;
}
