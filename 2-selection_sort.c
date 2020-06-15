#include "sort.h"

/**
 * selection_sort - sorts a list by choosing smallest int
 * from the right to position on left
 * @array: array of numbers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, min;

	if (array == NULL || size <= 0)
		return;
	if (size > 1)
	{
		for (i = 0; i < (size - 1); i++)
		{
			min = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				tmp = array[min];
				array[min] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
		}
	}
}
