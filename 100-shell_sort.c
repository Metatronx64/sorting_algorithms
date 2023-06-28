#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, gap = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial gap */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform Shell sort */
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			aux = array[i];
			for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != aux)
				array[j] = aux;
		}
		print_array(array, size);
	}
}

