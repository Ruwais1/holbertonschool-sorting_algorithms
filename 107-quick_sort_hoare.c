#include "sort.h"

/**
 * swap_ints - swaps two integers
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
	int tmp;

	if (*a == *b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
 * hoare_partition - partition using Hoare scheme
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

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

		if (array[i] != array[j])
			swap_ints(&array[i], &array[j], array, size);
	}
}

/**
 * quick_sort_rec - recursive function
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quick_sort_rec(array, low, p, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - main function
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
