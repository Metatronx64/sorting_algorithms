#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i = 0, j = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != i)
		{
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}

