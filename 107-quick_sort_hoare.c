#include "sort.h"


/**
 * hoare_partition - sorts pivot
 * @array: The array to sort
 * @start: The start index
 * @end: The end index
 * @size: The array size
 * Return: The index of the pivot
 */
size_t hoare_partition(int *array, size_t start, size_t end, size_t size)
{
	int pivot = array[end], tmp;
	size_t i = end, j = start;

	while (1)
	{
		while (array[i] > pivot)
			i--;

		while (array[j] < pivot)
			j++;

		if (j >= i)
			return (i);

		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;

		print_array(array, size);
	}
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

	idx_part = hoare_partition(array, start, end, size);

	quick_sort_rec(array, start, idx_part - 1, size);
	quick_sort_rec(array, idx_part + 1, end, size);
}

/**
 * quick_sort_hoare - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
