#ifndef __SORT__
#define __SORT__

#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*======================================================================*/
/*=================         Printing Algorithms        ==================*/
/*======================================================================*/

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: The size of the array
 *
 * Return: void
 */
void print_array(const int *array, size_t size);

/**
 * print_list - Prints a doubly linked list of integers
 * @list: The list to be printed
 *
 * Return: void
 */
void print_list(const listint_t *list);


/*======================================================================*/
/*=================          Sorting Algorithms        ==================*/
/*======================================================================*/

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using the Insertion Sort algorithm
 * @list: A pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list);

/**
 * selection_sort - Sorts an array of integers in ascending order using the Selection Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size);

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size);

/* Other sorting algorithms */

#endif /* __SORT__ */

