#include "binary_trees.h"

/**
  * binary_tree_insert_left - inserts a node as the left child of another node
  * @parent: is a pointer to the node to insert the left-child in
  * @value: the value to store in the new node
  * Return: pointer to new node or NULL on failure
  */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	if (parent->left != NULL)
	{
		parent->left->parent = node;
		node->left = parent->left;
	}
	parent->left = node;
	return (node);
}
