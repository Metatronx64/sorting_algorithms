#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme using the rightmost index as the pivot.
 * @array: Array of integers to be sorted.
 * @low: Index in the source array that begins the partition.
 * @high: Index in the source array that ends the partition.
 * @size: Number of elements in the array.
 *
 * Return: New index at which to start a new recursive partition.
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - Recursively sorts an array of integers by separating it into two
 * partitions using the Hoare quicksort algorithm.
 * @array: Array of integers to be sorted.
 * @low: Index in the source array that begins the partition.
 * @high: Index in the source array that ends the partition.
 * @size: Number of elements in the array.
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	size_t border;

	if (low < high)
	{
		border = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, border, size);
		hoare_quicksort(array, border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the quicksort
 * algorithm with Hoare partition scheme.
 * @array: Array of values to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}

