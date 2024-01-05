#include "binary_trees.h"

/**
 * binary_tree_size - Measures the tree_size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the tree_size of.
 *
 * Return: The tree_size of the tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;

	if (tree)
	{
		tree_size += 1;
		tree_size += binary_tree_size(tree->left);
		tree_size += binary_tree_size(tree->right);
	}

	return (tree_size);
}
