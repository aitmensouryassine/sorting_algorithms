#include "sort.h"

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
