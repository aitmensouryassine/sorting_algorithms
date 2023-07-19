#include "sort.h"

/**
 * bubble_sort - sort an array by using the Bubble algorithm
 * @array: the giving array to sorted
 * @size: the array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int var, flag_swap;

	for (i = 0, flag_swap = 1; i < size && flag_swap; i++)
	{
		flag_swap = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				var = array[j + 1];
				array[j + 1] = array[j];
				array[j] = var;
				print_array(array, size);
				flag_swap = 1;
			}
		}
	}

}
