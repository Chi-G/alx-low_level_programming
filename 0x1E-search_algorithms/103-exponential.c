#include "search_algos.h"

/**
 * exponential_search - a function that searches for a value in a
 * sorted array of integers using the Exponential search algorithm.
 * @array: a pointer to the first element of the array to search in.
 * @size: the number of elements in the array.
 * @value: the value to search for.
 *
 * Return: the first index where value is located or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0) {
        return -1;
    }

    if (array[0] == value) {
        return 0;
    }

    size_t bound = 1;
    
    while (bound < size && array[bound] <= value) {
        bound *= 2;
    }

    return binary_search(array, bound / 2, min(bound, size - 1), value);
}

/**
 * binary_search - a function that searches for a value in a sorted array.
 * @array: pointer to the first element in the array.
 * @left: the lower bound of the range to search.
 * @right: the upper bound of the range to search.
 * @value: the value to search for.
 *
 * Return: the index where value is located, or -1 if not found.
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        
        if (array[mid] == value) {
            return mid;
        }
        
        if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
