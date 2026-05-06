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

	if (a == b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: array
 * @low: start index
 * @high: end index
 * @size: size of array
 *
 * Return: partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(&array[i], &array[j], array, size);
	}
}

/**
 * quick_sort_hoare_rec - recursive quick sort
 * @array: array
 * @low: start index
 * @high: end index
 * @size: size
 */
void quick_sort_hoare_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quick_sort_hoare_rec(array, low, p, size);
		quick_sort_hoare_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts using Hoare scheme
 * @array: array
 * @size: size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_rec(array, 0, size - 1, size);
}
