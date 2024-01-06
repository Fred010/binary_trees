#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *turn, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	turn = tree->left;
	temp = turn->right;
	turn->right = tree;
	tree->left = temp;
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
