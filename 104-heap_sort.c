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

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * sift_down - heapify a subtree
 * @array: array
 * @size: size of array
 * @root: root index
 * @end: last index
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, swap;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == root)
			return;

		swap_ints(&array[root], &array[swap], array, size);
		root = swap;
	}
}

/**
 * heap_sort - sorts an array using heap sort
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int start, end;

	if (array == NULL || size < 2)
		return;

	start = (size / 2) - 1;
	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}

	end = size - 1;
	while (end > 0)
	{
		swap_ints(&array[0], &array[end], array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
