#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: first integer
 * @b: second integer
 * @array: array
 * @size: size of array
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
	int tmp;

	if (a == b || *a == *b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;

	print_array(array, size);
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: size of array
 *
 * Return: partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				swap_ints(&array[i], &array[j], array, size);
		}
	}

	if (i + 1 != high)
		swap_ints(&array[i + 1], &array[high], array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - recursive quick sort
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: size of array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts array using quick sort
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
