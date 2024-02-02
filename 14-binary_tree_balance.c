#include "binary_trees.h"

/**
  * binary_tree_balance - a function that measures the balance
  * factor of a binary tree
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (!tree)
		return (0);

	/* the height of the left branch */
	if (tree->left)
		lheight = _binary_tree_height(tree->left) + 1;

	/* the height of the right branch */
	if (tree->right)
		rheight = _binary_tree_height(tree->right) + 1;

	/* check  the heigher height between */
	/* the two branches (left or right) */

	return (lheight - rheight);
}



/**
  * _binary_tree_height - a function that measures the height of a binary tree
  * copy of  : binary_tree_height
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (!tree)
		return (0);

	/* the height of the left branch */
	if (tree->left)
		lheight = _binary_tree_height(tree->left) + 1;

	/* the height of the right branch */
	if (tree->right)
		rheight = _binary_tree_height(tree->right) + 1;

	/* check  the heigher height between */
	/* the two branches (left or right) */
	if (lheight > rheight)
		return (lheight);
	return (rheight);
}
