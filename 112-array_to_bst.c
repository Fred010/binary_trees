#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t id1, id2;

	if (array == NULL)
		return (NULL);

	for (id1 = 0; id1 < size; id1++)
	{
		for (id2 = 0; id2 < id1; id2++)
		{
			if (array[id2] == array[id1])
				break;
		}
		if (id2 == id1)
		{
			if (bst_insert(&tree, array[id1]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
