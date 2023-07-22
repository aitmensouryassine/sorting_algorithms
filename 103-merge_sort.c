#include "sort.h"

/**
 *
 */
void print_array_interval(char *msg, int *array, size_t start, size_t end)
{
	int i = 0;
	printf("[%s]: ", msg);
        while (array && start < end)
        {
                if (i++ > 0)
                        printf(", ");
                printf("%d", array[start]);
                ++start;
        }
        printf("\n");
}

/**
 *
 */
void merge(int *arr, size_t start, size_t middle, size_t end, int *array)
{
	size_t l, r, i;

	printf("Merging...\n");
	print_array_interval("left", array, start, middle);
	print_array_interval("right", array, middle, end);

	l = start, r = middle + 1, i = start;
	while (l <= middle && r <= end)
		if (array[l] < array[r])
			arr[i++] = array[l++];
		else
			arr[i++] = array[r++];

	while (l <= middle)
		arr[i++] = array[l++];

	while (r <= end)
		arr[i++] = array[r++];

	for (i = start; i < end + 1; i++)
		array[i] = arr[i];

	print_array_interval("Done", array, start, end);
}

/**
 *
 */
void merge_sort_rec(int *array, size_t start, size_t end, int *arr)
{
        size_t middle;

        /* base */
        if (end - start <= 1)
		return;

	middle = (start + end + 1) / 2;

	merge_sort_rec(array, start, middle, arr);
	merge_sort_rec(array, middle + 1, end, arr);

	merge(arr, start, middle, end, array);
}

/**
 *
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	arr = malloc(sizeof(int) * size);

	merge_sort_rec(array, 0, size - 1, arr);

	free(arr);
}
