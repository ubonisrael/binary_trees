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
			new_root = _binary_tree_rotate_left(tree);
		else
		{
			new_root = _binary_tree_rotate_right(tree->right);
			tree->right = new_root;
			new_root = _binary_tree_rotate_left(tree);
		}
	}
	else
	{
		if (binary_tree_balance(tree->left) >= 0)
			new_root = _binary_tree_rotate_right(tree);
		else
		{
			new_root = _binary_tree_rotate_left(tree->left);
			tree->left = new_root;
			new_root = _binary_tree_rotate_right(tree);
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


/**
  * _binary_tree_rotate_right - performs a right-rotation on a binary tree
  * @tree: pointer to the root node of tree to rotate
  * Return: new root node of the tree once rotated
  */

binary_tree_t *_binary_tree_rotate_right(binary_tree_t *tree)
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

/**
  * _binary_tree_rotate_left - performs a left-rotation on a binary tree
  * @tree: pointer to the root node of tree to rotate
  * Return: new root node of the tree once rotated
  */

binary_tree_t *_binary_tree_rotate_left(binary_tree_t *tree)
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
