#include "search_algos.h"

/**
 * binary_recursive - search for a value in an array using recursion
 * @array: int array.
 * @l: left value of the array.
 * @r: right value of the array.
 * @value: value to search in the array.
 * Return: index of occurrence or -1 if not found or array is NULL.
 */
int binary_recursive(int *array, int l, int r, int value)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		printf("Searching in array: ");

		for (int i = l; i < r; i++)
			printf("%d, ", array[i]);

		printf("%d\n", array[r]);

		if (array[mid] == value)
		{
			if (array[mid - 1] == value)
				return (binary_recursive(array, l, mid, value));

			return (mid);
		}

		if (array[mid] > value)
			return (binary_recursive(array, l, mid - 1, value));

		return (binary_recursive(array, mid + 1, r, value));
	}

	return (-1);
}

/**
 * advanced_binary - call binary search function
 * @array: int array.
 * @size: size of array.
 * @value: value to search in the array.
 * Return: binary_recursive function return value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
