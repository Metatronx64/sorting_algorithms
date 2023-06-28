#include "sort.h"

/**
 * partition - Partitions an array into two sub-arrays based on a pivot element
 * @array: The array to be partitioned
 * @first: The index of the first element in the sub-array
 * @last: The index of the last element in the sub-array
 * @size: The size of the array
 *
 * Return: The pivot index
 */
int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - Recursively sorts an array of integers using the Quick sort algorithm
 * @array: The array to be sorted
 * @first: The index of the first element in the sub-array
 * @last: The index of the last element in the sub-array
 * @size: The size of the array
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}

