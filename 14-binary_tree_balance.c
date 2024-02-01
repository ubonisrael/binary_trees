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

/**
 * _balance_tree - rotates a node left or right to balance an unbalanced AVL
 * @tree: pointer to node to apply rotation
 * @tree_parent: pointer to node to tree's parent
 * Return: pointer to new root
 */

binary_tree_t *_balance_tree(binary_tree_t *tree, binary_tree_t *tree_parent)
{
	int lh = 0, rh = 0;
	binary_tree_t *new_root;

	if (tree->left)
		lh = _binary_tree_height(tree->left) + 1;
	if (tree->right)
		rh = _binary_tree_height(tree->right) + 1;
	if (rh > lh)
	{
		if (binary_tree_balance(tree->right) <= 0)
			new_root = binary_tree_rotate_left(tree);
		else
		{
			new_root = binary_tree_rotate_right(tree->right);
			tree->right = new_root;
			new_root = binary_tree_rotate_left(tree);
		}
	}
	else
	{
		if (binary_tree_balance(tree->left) >= 0)
			new_root = binary_tree_rotate_right(tree);
		else
		{
			new_root = binary_tree_rotate_left(tree->left);
			tree->left = new_root;
			new_root = binary_tree_rotate_right(tree);
		}
	}
	if (tree_parent)
	{
		if (new_root->n > (tree_parent)->n)
			(tree_parent)->right = new_root;
		else
			(tree_parent)->left = new_root;
	}
	new_root->parent = tree_parent;
	tree = new_root;
	return (tree);
}
