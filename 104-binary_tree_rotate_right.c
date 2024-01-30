#include "binary_trees.h"

/**
  * binary_tree_rotate_right - performs a right-rotation on a binary tree
  * @tree: pointer to the root node of tree to rotate
  * Return: new root node of the tree once rotated
  */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_right;

	if (tree == NULL)
		return (NULL);

	old_root = tree;
	new_root = old_root->left;
	if (new_root->right)
		old_right = new_root->right;
	else
		old_right = NULL;

	new_root->parent = old_root->parent;
	new_root->right = old_root;
	old_root->parent = new_root;
	old_root->left = old_right;
	if (old_right != NULL)
		old_right->parent = old_root;

	return (new_root);
}
