#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *turn, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	turn = tree->right;
	temp = turn->left;
	turn->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = turn;
	turn->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = turn;
		else
			temp->right = turn;
	}

	return (turn);
}
