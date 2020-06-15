/*
 * ==========================================
 *
 *       Filename:  3-quick_sort.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  15/06/2020 11:24:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrew Kalil & Samuel Gómez
 *   Organization:  Holberton
 *
 * ==========================================
 */

#include "sort.h"
/**
 * quick_sort - function to quick dual_pivot_sort an array using lomuto method
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0 || size == 1)
		return;
	dual_pivot_sort(array, 0, size - 1, size);
}

/**
 * dual_pivot_sort - function to call recursive and create new pivots
 * @array: array to be sorted
 * @start: beginning of sorting array
 * @end: end of sorting array
 * @size: size of array
 * Return: void
 */
void dual_pivot_sort(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot;

	if (end == 0 || end <= start)
		return;
	pivot = partition(array, start, end, size);
	if (pivot != 0 && pivot > start)
		dual_pivot_sort(array, start, pivot - 1, size);
	if (pivot < size - 1)
		dual_pivot_sort(array, pivot + 1, end, size);
}

/**
 * partition - function to partition array according to pivot
 * @array: array to be partitioned
 * @start: beginning of comparison index
 * @pivot: partition index
 * @size: size of array
 * Return: void
 */
size_t partition(int *array, size_t start, size_t pivot, size_t size)
{
	size_t a;

	for (a = start; a < pivot; a++)
	{
		if (array[a] < array[pivot])
		{
			if (a != start)
			{
				swap(&array[start], &array[a]);
				print_array(array, size);
			}
			start++;
		}
	}
	if (array[start] > array[pivot])
	{
		swap(&array[start], &array[pivot]);
		pivot = start;
		print_array(array, size);
	}
	return (pivot);
}

/**
 * swap - function to swap elements
 * @a: element 1
 * @b: element 2
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}
