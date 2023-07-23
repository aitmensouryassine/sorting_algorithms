#include "sort.h"

/**
 * print_array_interval - prints array interval
 * @array: the giving array
 * @start: the start index of the array
 * @end: the end index of the array
 */
void print_array_interval(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * sort_up - sorts up an array
 * @array: the giving array
 * @start: the start index of the array
 * @end: the end index of the array
 */
void sort_up(int *array, int start, int end)
{
	int low, tmp, i, j;

	for (i = start; i < end - 1; i++)
	{
		low = i;
		for (j = i + 1; j < end; j++)
			if (array[low] >  array[j])
				low = j;
		if (low != i)
		{
			tmp = array[i];
			array[i] = array[low];
			array[low] = tmp;
		}
	}
}

/**
 * sort_down - sorts down an array
 * @array: the giving array
 * @start: the start index of the array
 * @end: the end index of the array
 */
void sort_down(int *array, int start, int end)
{
	int max, tmp, i, j;

	for (i = start; i < end - 1; i++)
	{
		max = i;
		for (j = i + 1; j < end; j++)
			if (array[max] <  array[j])
				max = j;
		if (max != i)
		{
			tmp = array[i];
			array[i] = array[max];
			array[max] = tmp;
		}
	}
}

/**
 * bitonic_recursion - bitonic sort recursion
 * @array: the giving array
 * @start: the start index of the array
 * @end: the end index of the array
 * @dir: the sort direction
 * @size: the size of the array
 */
void bitonic_recursion(int *array, int start, int end, char dir, size_t size)
{
	char *direction;

	if (end - start < 2)
		return;

	direction = (dir == 'U') ? "UP" : "DOWN";

	printf("Merging [%d/%ld] (%s):\n", end - start, size, direction);
	print_array_interval(array, start, end);

	if (end - start == 2)
		return;

	bitonic_recursion(array, start, (start + end) / 2, 'U', size);
	sort_up(array, start, (start + end) / 2);
	printf("Result [%d/%ld] (%s):\n", (((end + start) / 2) - start), size, "UP");
	print_array_interval(array, start, (start + end) / 2);


	bitonic_recursion(array, (start + end) / 2, end, 'D', size);
	sort_down(array, (start + end) / 2, end);
	printf("Result [%d/%ld] (%s):\n", (end - (end + start) / 2), size, "DOWN");
	print_array_interval(array, (start + end) / 2, end);
}

/**
 * bitonic_sort - sorts an array by using bitonic sort algorithm
 * @array: the giving array
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{

	if (size < 2 || !array)
		return;

	bitonic_recursion(array, 0, size, 'U', size);
	sort_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_array(array, size);
}
