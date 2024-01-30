#include "binary_trees.h"

/**
  * binary_tree_size - a function that measures the size of a binary tree
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (tree->left)
		count = count + binary_tree_size(tree->left);

	if (tree->right)
		count = count + binary_tree_size(tree->right);

	return (count + 1);
}
