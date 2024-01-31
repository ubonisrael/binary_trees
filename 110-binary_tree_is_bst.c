#include "binary_trees.h"

/**
 * binary_tree_is_bst - a function that checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree
 * Return: 0, If tree is NULL.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int max_val, min_val;

	if (!tree)
		return (0);

	min_val = bst_min_value(tree);
	max_val = bst_max_value(tree);

	return (is_bst_util(tree, min_val, max_val));
}

/**
 * is_bst_util - helper function to check if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree
 * @min: minimum allowed value for the current node
 * @max: maximum allowed value for the current node
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	int l_is_vld, r_is_vld;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	l_is_vld = is_bst_util(tree->left, min, tree->n);
	r_is_vld = is_bst_util(tree->right, tree->n, max);

	return (l_is_vld && r_is_vld);
}
/**
 * bst_max_value - finds the maximum value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST
 * Return: The maximum value in the BST or 0 if the tree is empty.
 */
int bst_max_value(const binary_tree_t *tree)
{
	int h_val, l_val, value;

	if (!tree)
		return (INT_MIN);

	l_val = bst_max_value(tree->left);
	h_val = bst_max_value(tree->right);

	if (l_val > h_val)
		value = l_val;
	else
		value = h_val;

	if (value < tree->n)
		value = tree->n;

	return (value);
}

/**
 * bst_min_value - finds the minimum value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST
 * Return: The minimum value in the BST or 0 if the tree is empty.
 */
int bst_min_value(const binary_tree_t *tree)
{
	int h_val, l_val, value;

	if (!tree)
		return (INT_MAX);

	l_val = bst_min_value(tree->left);
	h_val = bst_min_value(tree->right);

	if (l_val < h_val)
		value = l_val;
	else
		value = h_val;

	if (value > tree->n)
		value = tree->n;

	return (value);
}
