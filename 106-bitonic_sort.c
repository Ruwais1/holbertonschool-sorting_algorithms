#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @dir: The direction to sort in (1 for UP, 0 for DOWN).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t i, jump = seq / 2;
	int temp;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((dir == 1 && array[i] > array[i + jump]) ||
			    (dir == 0 && array[i] < array[i + jump]))
			{
				temp = array[i];
				array[i] = array[i + jump];
				array[i + jump] = temp;
			}
		}
		bitonic_merge(array, size, start, jump, dir);
		bitonic_merge(array, size, start + jump, jump, dir);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t cut = seq / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", (unsigned long)seq,
		       (unsigned long)size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 1);
		bitonic_seq(array, size, start + cut, cut, 0);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", (unsigned long)seq,
		       (unsigned long)size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
