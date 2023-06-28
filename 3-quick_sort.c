#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - Partitions the array and selects a pivot element for Quick sort.
 * @array: The array to be partitioned.
 * @lo: The lower bound index.
 * @hi: The higher bound index.
 * @size: The size of the array.
 *
 * Return: The updated pivot index.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi], temp = 0;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - Recursively performs Quick sort on the array.
 * @array: The array to be sorted.
 * @lo: The lower bound index.
 * @hi: The higher bound index.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_s(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_s(array, lo, pivot - 1, size);
		quick_s(array, pivot + 1, hi, size);
	}
}

