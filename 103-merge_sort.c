#include "sort.h"

/**
 *
 */
void merge(int *arr, size_t start, size_t middle, size_t end, int *array)
{
	size_t l, r, i;

	printf("Merging...\n");

	printf("[left]: ");
	i = start;
	while (array && i < middle)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");

	printf("[right]: ");
	i = middle;
	while (array && i < end)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");

	l = start, r = middle;
	while (l < middle && r < end)
		if (array[l] < array[r])
			arr[i++] = array[l++];
		else
			arr[i++] = array[r++];

	while (l < middle)
		arr[i++] = array[l++];

	while (r < end)
		arr[i++] = array[r++];

	printf("[Done]: ");
	print_array(arr, end);
}

/**
 *
 */
int *merge_sort_rec(int *array, size_t start, size_t end, int *arr)
{
        size_t middle;

        /* base */
        if ((end - start) == 1)
                return (array);

        middle = (start + end) / 2;

        merge_sort_rec(array, start, middle - 1, arr);
	merge_sort_rec(array, middle, end, arr);

        merge(arr, start, middle, end, array);

	return (array);
}

/**
 *
 */
void merge_sort(int *array, size_t size)
{
	int *arr;
	size_t i;

	arr = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		arr[i] = array[i];

	merge_sort_rec(array, 0, size, arr);

	free(arr);
}
