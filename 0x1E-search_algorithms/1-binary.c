#include "search_algos.h"

/**
 * binary_search - Searches for a value in an array of integers
 *                using the binary search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where the value is located, or -1 if
 *         the value is not present or the array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1; // Handle case where the array is NULL

    size_t left = 0;
    size_t right = size - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;

        printf("Searching in array: ");
        for (size_t i = left; i <= right; i++) {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
