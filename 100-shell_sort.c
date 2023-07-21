#include "sort.h"

/**
 * insertion_sort - sorting an array by using insertion algorithm
 * @array: the giving array
 * @size: the size of the array
 */
void insertion_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	for (i = 0; i < size; i++)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			tmp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = tmp;
			j--;
		}
	}
}



/**
 * shell_sort - sorting an array by using shell sort
 * @array: the giving array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	while (gap < size)
	{
		gap = (gap * 3) + 1;
	}
	while ((gap = (gap - 1) / 3) > 0)
	{
		for (i = 0; i + gap < size; i++)
		{
			for (j = i + gap; (int)(j - gap) >= 0; j = j - gap)
			{
				if (array[j] < array[j - gap])
				{
					tmp = array[j];
					array[j] = array[j - gap];
					array[j - gap] = tmp;
				}
			}
		}
		print_array(array, size);
	}
}
