#include "sort.h"

/**
 * swap - swaps the elements
 * @a: first element
 * @b: second element
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array
 * @array: the array to partition
 * @low: first element
 * @high: last element
 * @size: size of the array
 * Return: pivot index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * sort - sorts the array
 * @array: array to sort
 * @low: low
 * @high: high
 * @size: size of the array
 * Return: void
 */

void sort(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high, size);

		sort(array, low, pivot_idx - 1, size);
		sort(array, pivot_idx + 1, high, size);
	}
}

/**
 * quick_sort - quick sort
 * @array : the array
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	sort(array, 0, size - 1, size);
}
