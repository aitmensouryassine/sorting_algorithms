#include "sort.h"


/**
 * lomutoPartition - sorts pivot
 * @array: The array to sort
 * @start: The start index
 * @end: The end index
 * @size: The array size
 * Return: The index of the pivot
 */
size_t lomutoPartition(int *array, size_t start, size_t end, size_t size)
{
	int pivot = array[end], tmp;
	size_t i = start - 1, j;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				/* swap */
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;

				print_array(array, size);
			}
		}
	}

	i++;
	if (array[i] > pivot)
	{
		/* swap */
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;

		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_rec - sorts an array using the quick sort algorithm
 * @array: The array to sort
 * @start: The start index
 * @end: The end index
 * @size: The array size
 */
void quick_sort_rec(int *array, int start, int end, size_t size)
{
	size_t idx_part;

	/* base */
	if (end < start)
		return;

	idx_part = lomutoPartition(array, start, end, size);

	quick_sort_rec(array, start, idx_part - 1, size);
	quick_sort_rec(array, idx_part + 1, end, size);
}

/**
 * quick_sort - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, 0, size - 1, size);
}
