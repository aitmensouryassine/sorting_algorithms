#include "sort.h"

/**
 * print_array_interval - prints an array interval
 * @msg: the giving msg
 * @array: the giving array to be printed
 * @start: the start printted index
 * @end: the end printed index
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
 * merge - merges two subarrays
 * @arr: the working array
 * @start: the start index
 * @middle: the index of the middle
 * @end: the end index
 * @array: the giving array
*/
void merge(int *arr, size_t start, size_t middle, size_t end, int *array)
{
	size_t l, r, i;

	printf("Merging...\n");
	print_array_interval("left", array, start, middle);
	print_array_interval("right", array, middle, end + 1);

	l = start, r = middle, i = start;
	while (l < middle && r <= end)
		if (array[l] < array[r])
			arr[i++] = array[l++];
		else
			arr[i++] = array[r++];

	while (l < middle)
		arr[i++] = array[l++];

	while (r <= end)
		arr[i++] = array[r++];

	for (i = start; i < end + 1; i++)
		array[i] = arr[i];

	print_array_interval("Done", array, start, end + 1);
}

/**
 * merge_sort_rec - applies the merge sort for two subarrays
 * @array: the giving array
 * @start: the start index of the array
 * @end: the end index of the array
 * @arr: the working array
*/
void merge_sort_rec(int *array, size_t start, size_t end, int *arr)
{
	size_t middle;

	if (end - start < 1)
		return;

	middle = (start + end + 1) / 2;

	merge_sort_rec(array, start, middle - 1, arr);
	merge_sort_rec(array, middle, end, arr);

	merge(arr, start, middle, end, array);
}

/**
 * merge_sort - sorts an array by using the merge sorting algorithm
 * @array: the giving array
 * @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_sort_rec(array, 0, size - 1, arr);

	free(arr);
}
