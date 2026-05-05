#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len;
	int temp, swapped;

	if (array == NULL || size < 2)
		return;

	len = size;
	while (len > 0)
	{
		swapped = 0;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/* Swap the elements */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				
				/* Print the array after each swap */
				print_array(array, size);
				
				swapped = 1;
			}
		}
		/* If no swaps occurred, the array is sorted */
		if (swapped == 0)
			break;
		len--;
	}
}
