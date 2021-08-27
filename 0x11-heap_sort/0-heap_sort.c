#include "sort.h"

/**
 * swap - Swap two pointers
 * @a: pointer to first integer
 * @b: pointer to second integer
 * Return: no return value
 **/

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * make_heap - convert array into a heap
 * @array: array to convert into a heap
 * @size: size of the array
 * @i: largest point
 * @new_size: new size of the array
 * Return: no return value
 **/

void make_heap(int *array, int size, int i, int new_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, new_size);
		make_heap(array, size, largest, new_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: pointer to an array of integers
 * @size: size of the array
 * Return: no return value
 **/

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		make_heap(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		if (array[0] >= array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}

		make_heap(array, i, 0, size);
	}
}
