#include "sort.h"

/**
 * swap_ints - swaps two integers
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
 * hoare_partition - Hoare partition with last element as pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j = high - 1;

	while (1)
	{
		while (i <= high && array[i] < pivot)
			i++;

		while (j >= low && array[j] > pivot)
			j--;

		if (i >= j)
			break;

		swap_ints(&array[i], &array[j], array, size);
	}

	/* place pivot in correct position */
	if (array[i] != array[high])
		swap_ints(&array[i], &array[high], array, size);

	return (i);
}

/**
 * quick_sort_rec - recursive helper
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
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
