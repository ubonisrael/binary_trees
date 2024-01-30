#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * A NULL pointer is not a leaf
 * Return: 0, If tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count_1 = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	count_1 = count_1 + binary_tree_leaves(tree->left);
	count_1 = count_1 + binary_tree_leaves(tree->right);

	return (count_1);
}
