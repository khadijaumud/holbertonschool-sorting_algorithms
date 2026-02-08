#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick Sort algorithm (Lomuto partition)
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j, low, high;
	int temp;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	if (low < high)
	{
		i = low;
		for (j = low; j < high; j++)
		{
			if (array[j] < array[high])
			{
				if (i != j)
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					print_array(array, size);
				}
				i++;
			}
		}
		if (i != high)
		{
			temp = array[i];
			array[i] = array[high];
			array[high] = temp;
			print_array(array, size);
		}
		if (i > 0)
			quick_sort(array, i);
		quick_sort(array + i + 1, size - i - 1);
	}
}
