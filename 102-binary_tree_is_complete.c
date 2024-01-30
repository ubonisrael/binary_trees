#include "binary_trees.h"

size_t is_complete(binary_tree_t *tree, size_t index, size_t tree_size);
/**
  * binary_tree_is_complete - checks if a binary tree is complete
  * @tree: pointer to binary tree to be checked
  * Return: void
  */

int binary_tree_is_complete(binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	return (is_complete(tree, 0, size));
}

/**
  * is_complete - checks if a binary tree is complete
  * @tree: pointer to binary tree to be checked
  * @index: level of tree
  * @tree_size: size of the tree
  * Return: 1 if true, else 0
  */

size_t is_complete(binary_tree_t *tree, size_t index, size_t tree_size)
{
	if (tree == NULL)
		return (1);
	if (index >= tree_size)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, tree_size) &&
			is_complete(tree->right, 2 * index + 2, tree_size));
}

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
