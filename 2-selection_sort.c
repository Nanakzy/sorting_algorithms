#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;
	size_t k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			for (k = 0; k < size - 1; k++)
				printf("%d, ", array[k]);
			printf("%d\n", array[size - 1]);
		}
	}
}
