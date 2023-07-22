#include "sort.h"


/**
 * left_node_index - gets the left node index
 * @i: the giving parent node index
 * Return: the left child node index
 */
int left_node_index(int i)
{
	return (2 * i + 1);
}

/**
 * right_node_index - gets the right node index
 * @i: the giving parent node index
 * Return: the right child node index
 */
int right_node_index(int i)
{
	return (2 * i + 2);
}

/**
 * get_largest - gets the largest node index
 * @array: the giving array
 * @i: the giving parent node index
 * @max: the max size of the tree
 * Return: the largest node index
 */
int get_largest(int *array, int i, int max)
{
	int largest = i, left, right;

	left = left_node_index(i);
	right = right_node_index(i);

	if (left < max && array[left] > array[largest])
		largest = left;
	if (right < max && array[right] > array[largest])
		largest = right;
	return (largest);
}



/**
 * heapify - To heapify a subtree rooted with node i
 * @array: the giving array
 * @size: the array size
 * @i: the node i
 * @max: max tree length
 */
void heapify(int *array, size_t size, int i, int max)
{
	int largest, tmp;

	largest = get_largest(array, i, max);

	if (i != largest)
	{
		/* Swap */
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;

		print_array(array, size);
		heapify(array, size, largest, max);
	}
}



/**
 * heap_sort - sorts an array by using heap sort
 * @array: the giving array
 * @size: the array size
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (size < 2 || !array)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i > 0; i--)
	{
		/* Swap */
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;

		print_array(array, size);
		heapify(array, size, 0, i);
	}

}
