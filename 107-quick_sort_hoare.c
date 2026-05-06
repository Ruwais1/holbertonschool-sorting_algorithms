#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
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
 * hoare_partition - Hoare partition
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		/* move i right */
		do {
			i++;
		} while (i <= high && array[i] < pivot);

		/* move j left */
		do {
			j--;
		} while (j >= low && array[j] > pivot);

		if (i >= j)
			return (j);

		swap_ints(&array[i], &array[j], array, size);
	}
}

/**
 * quick_sort_rec - recursive
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
 * quick_sort_hoare - main
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
