#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *matriarch, *patriarch;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);

	matriarch = first->parent, patriarch = second->parent;
	if (first == patriarch || !matriarch || (!matriarch->parent && patriarch))
		return (binary_trees_ancestor(first, patriarch));
	else if (matriarch == second || !patriarch ||
			(!patriarch->parent && matriarch))
		return (binary_trees_ancestor(matriarch, second));
	return (binary_trees_ancestor(matriarch, patriarch));
}
