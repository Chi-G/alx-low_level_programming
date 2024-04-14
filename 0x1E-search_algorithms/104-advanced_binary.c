#include "search_algos.h"

/**
 * advanced_binary - a function that searches for a value in a
 * sorted array of integers using the advanced binary search algorithm.
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        printf("Searching in array: [%d, %d]\n", left, right);

        if (array[mid] == value) {
            return mid;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
