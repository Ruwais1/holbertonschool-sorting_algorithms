#include "sort.h"
#include <stdlib.h>

/**
 * get_max - gets maximum value in array
 * @array: array
 * @size: size
 *
 * Return: max value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

/**
 * counting_sort - stable counting sort for radix
 * @array: array
 * @size: size
 * @exp: exponent (digit place)
 * @output: temp array
 */
void counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;

	i = 0;
	while (i < size)
	{
		count[(array[i] / exp) % 10]++;
		i++;
	}

	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}

	i = size;
	while (i > 0)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
		i--;
	}

	i = 0;
	while (i < size)
	{
		array[i] = output[i];
		i++;
	}
}

/**
 * radix_sort - sorts array using LSD radix sort
 * @array: array
 * @size: size
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

	exp = 1;
	while (max / exp > 0)
	{
		counting_sort(array, size, exp, output);
		print_array(array, size);
		exp *= 10;
	}

	free(output);
}
