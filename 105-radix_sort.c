#include "sort.h"
#include <stdlib.h>

/**
 * get_max - gets the maximum value in the array
 * @array: array
 * @size: size of array
 *
 * Return: max value
 */
static int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - counting sort used by radix sort
 * @array: array
 * @size: size
 * @exp: current digit
 * @output: temp array
 */
static void counting_sort_radix(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] =
			array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts array using LSD radix sort
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
