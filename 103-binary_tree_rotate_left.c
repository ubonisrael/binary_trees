#include "binary_trees.h"

/**
  * binary_tree_rotate_left - performs a left-rotation on a binary tree
  * @tree: pointer to the root node of tree to rotate
  * Return: new root node of the tree once rotated
  */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_left;

	if (tree == NULL)
		return (NULL);

	old_root = tree;
	new_root = old_root->right;
	if (new_root->left)
		old_left = new_root->left;
	else
		old_left = NULL;

	new_root->parent = old_root->parent;
	new_root->left = old_root;
	old_root->parent = new_root;
	old_root->right = old_left;
	if (old_left != NULL)
		old_left->parent = old_root;

	return (new_root);
}
