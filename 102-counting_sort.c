#include "sort.h"

/**
 * counting_sort - sorts an array by using counting sort algorithm
 * @array: the giving array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = array[0], i;
	int *counter, *sorted;

	for (i = 1; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];

	counter = malloc(sizeof(int) * (k + 1));
	if (!counter)
		return;
	for (i = 0; i < (k + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < k; i++)
		counter[i + 1] += counter[i];
	print_array(counter, k + 1);
	sorted = malloc(sizeof(int) * (size));
	if (!sorted)
	{
		free(counter);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		sorted[counter[array[i] - 1]] = array[i];
		counter[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(sorted);
	free(counter);
}
