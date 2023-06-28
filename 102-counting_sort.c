#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the Counting Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int *counter = NULL;
	int max_value = 0;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Create a counter array with size equal to (max_value + 1) */
	counter = malloc(sizeof(int) * (max_value + 1));
	if (counter == NULL)
		return;

	/* Initialize counter array with zeros */
	for (i = 0; i <= (unsigned int)max_value; i++)
		counter[i] = 0;

	/* Count the occurrences of each element */
	for (i = 0; i < size; i++)
		counter[array[i]]++;

	/* Update the counter array to hold the cumulative counts */
	for (i = 1; i <= (unsigned int)max_value; i++)
		counter[i] += counter[i - 1];

	/* Create a temporary array to store the sorted elements */
	int *sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(counter);
		return;
	}

	/* Fill the sorted_array in the correct order */
	for (i = 0; i < size; i++)
	{
		sorted_array[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(counter);
	free(sorted_array);
}

