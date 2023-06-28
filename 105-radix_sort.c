#include "sort.h"
#include <stdlib.h>

/**
 * init_bucket_count - Resets bucket_count values to 0
 * @bucket_count: Array containing the amounts of members for arrays in `buckets`
 */
void init_bucket_count(int *bucket_count)
{
	int i;

	for (i = 0; i < 10; i++)
		bucket_count[i] = 0;
}

/**
 * build_buckets - Allocates space for arrays to be held in `buckets`
 * @buckets: Array of arrays, each containing sorted members of `array`
 * @bucket_count: Array containing the amounts of members for arrays in `buckets`
 */
void build_buckets(int *bucket_count, int **buckets)
{
	int *bucket;
	int i;

	for (i = 0; i < 10; i++)
	{
		bucket = malloc(sizeof(int) * bucket_count[i]);
		if (!bucket)
		{
			for (; i > -1; i--)
				free(buckets[i]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
		buckets[i] = bucket;
	}
	init_bucket_count(bucket_count);
}

/**
 * find_max - Searches an array of integers for the highest value
 * @array: Array of values to be searched
 * @size: Number of elements in the array
 * Return: The largest integer stored in the array
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * into_array - Flattens buckets into an array sorted by the current digit place,
 * then prints the results and frees the current buckets for the next pass
 * @array: Array of values to be printed
 * @size: Number of elements in the array
 * @buckets: Array of arrays, each containing sorted members of `array`
 * @bucket_count: Array containing the amounts of members for arrays in `buckets`
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
	int i, j, k;

	/* Flatten bucket members in order into an array sorted by place */
	for (k = 0, i = 0; k < 10; k++)
	{
		for (j = 0; j < bucket_count[k]; j++, i++)
			array[i] = buckets[k][j];
	}
	/* Print the results */
	print_array(array, size);
	/* Free the buckets from the current pass */
	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix Sort algorithm,
 * starting with the LSD (least significant (1s place) digit) and sorting by the next digit to the left.
 * The size of `bucket_count` here is determined by the maximum range of key variance (digits 0-9),
 * and other solutions may be needed for much larger ranges.
 * @array: Array of values to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_count[10];
	int max, max_digits, pass, divisor, digit;
	size_t i;

	if (!array || size < 2)
		return;
	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(1);
	/* Find the number of places in the largest element */
	max = find_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;
	/* Perform one sorting pass for each place in max_digits */
	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		init_bucket_count(bucket_count);
		/* Find the number of members in each bucket */
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			bucket_count[digit]++;
		}
		build_buckets(bucket_count, buckets);
		/* Fill the buckets, sorting by the digit at the current power of 10 */
		for (i = 0; i < size; i++)
		{
			/* Find the digit of the source element at that power of 10 */
			digit = (array[i] / divisor) % 10;
			/* Place the member of the source array in the digit's bucket */
			buckets[digit][bucket_count[digit]] = array[i];
			/* Record the increase in bucket fill level */
			bucket_count[digit]++;
		}
		into_array(array, size, buckets, bucket_count);
	}
	free(buckets);
}

