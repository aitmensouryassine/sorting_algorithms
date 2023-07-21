#include "sort.h"

/**
 * counting_sort - sorts an array by using counting sort algorithm
 * @array: the giving array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k;
	int *counter, *sorted;

	if (size < 2 || !array)
		return;
	for (i = 1, k = array[0]; i < size; i++)
		if (array[i] > k)
			k = array[i];

	counter = malloc(sizeof(size_t) * (k + 1));
	if (!counter)
		return;
	for (i = 0; (int)i < k + 1; i++)
		counter[i] = 0;
	for (i = 0; i < size; i++)
		counter[array[i]] += 1;
	for (i = 1; (int)i <= k; i++)
		counter[i] += counter[i - 1];
	print_array(counter, k + 1);
	sorted = malloc(sizeof(int) * (size));
	if (!sorted)
	{
		free(counter);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(counter);
}
