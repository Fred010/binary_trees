#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *trend, *new;

	if (tree != NULL)
	{
		trend = *tree;

		if (trend == NULL)
		{
			new = binary_tree_node(trend, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < trend->n)
		{
			if (trend->left != NULL)
				return (bst_insert(&trend->left, value));

			new = binary_tree_node(trend, value);
			if (new == NULL)
				return (NULL);
			return (trend->left = new);
		}

		if (value > trend->n)
		{
			if (trend->right != NULL)
				return (bst_insert(&trend->right, value));

			new = binary_tree_node(trend, value);
			if (new == NULL)
				return (NULL);
			return (trend->right = new);
		}
	}

	return (NULL);
}
