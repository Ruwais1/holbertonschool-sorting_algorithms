#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the maximum gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start sorting with the largest gap, then decrease */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			/* Shift earlier gap-sorted elements up until correct location */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		/* Print the array each time the interval decreases */
		print_array(array, size);

		/* Decrease the gap using the inverse of Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
