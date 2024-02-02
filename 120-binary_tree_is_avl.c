#include "binary_trees.h"

int _binary_tree_balance(const binary_tree_t *tree);
size_t _binary_tree_height(const binary_tree_t *tree);
int is_avl_util(const binary_tree_t *tree, int min, int max);
/**
  * binary_tree_balance - a function that measures the balance
  * factor of a binary tree
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
int _binary_tree_balance(const binary_tree_t *tree)
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
 * is_avl_util - helper function to check if a binary tree is a valid AVL
 * @tree: pointer to the root node of the tree
 * @min: minimum allowed value for the current node
 * @max: maximum allowed value for the current node
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_avl_util(const binary_tree_t *tree, int min, int max)
{
	int bal, l_is_vld, r_is_vld;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	bal = _binary_tree_balance(tree);
	if (bal < -1 || bal > 1)
		return (0);

	l_is_vld = is_avl_util(tree->left, min, tree->n);
	r_is_vld = is_avl_util(tree->right, tree->n, max);

	return (l_is_vld && r_is_vld);
}

/**
  * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
  * @tree: pointer to the root node of the tree
  * Return: 1 if true, else 0
  */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_util(tree, INT_MIN, INT_MAX));
}
