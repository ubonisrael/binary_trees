#include "binary_trees.h"

/**
 * binary_tree_uncle - a function that finds the uncle of a node
 * @node: pointer to the root node of the tree
 *
 * A NULL pointer is not a node
 * Return: NULL, If node has no uncle or If node is NULL or
 * the parent is NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (!node->parent)
		return (NULL);

	return (_binary_tree_sibling(node->parent));
}

/**
 * _binary_tree_sibling - a function that finds the sibling of a node
 * copy of : binary_tree_sibling
 * @node: pointer to the root node of the tree
 *
 * A NULL pointer is not a node
 * Return: NULL, If node has no sibling or If node is NULL or
 * the parent is NULL.
 */
binary_tree_t *_binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (!node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
