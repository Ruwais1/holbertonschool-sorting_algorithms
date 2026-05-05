#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *out;
	int max, i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	out = malloc(sizeof(int) * size);
	if (out == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		out[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = out[i];

	free(count);
	free(out);
}
