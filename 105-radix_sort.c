#include "sort.h"

/**
 * get_array_max_value - get the max value in an array of ints
 * @array: The given array
 * @size: the size of the array
 * Return: Return the max value
 */
int get_array_max_value(int *array, size_t size)
{
	int max;
	size_t i;

	for (i = 1, max = array[0]; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * count_sort - use count sort algo to sort an array
 * @array: the given array to sort
 * @size: the size of the array
 * @exponent: the exponenet
 */
void count_sort(int *array, size_t size, int exponent)
{
	size_t i;
	int k = 10;
	int *counter, *sorted;

	counter = malloc(sizeof(size_t) * k);
	if (!counter)
		return;
	for (i = 0; (int)i < k; i++)
		counter[i] = 0;
	for (i = 0; i < size; i++)
		counter[(array[i] / exponent) % 10] += 1;
	for (i = 1; (int)i < k; i++)
		counter[i] += counter[i - 1];

	sorted = malloc(sizeof(int) * (size));
	if (!sorted)
	{
		free(counter);
		return;
	}
	for (i = size - 1; (int)i >= 0; i--)
	{
		sorted[counter[(array[i] / exponent) % 10] - 1] = array[i];
		counter[(array[i] / exponent) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(counter);
}

/**
 * radix_sort - sorts an array using the radix algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, expt;

	if (size < 2 || !array)
		return;

	max = get_array_max_value(array, size);

	for (expt = 1; (max / expt) > 0; expt *= 10)
	{
		count_sort(array, size, expt);
		print_array(array, size);
	}
}
