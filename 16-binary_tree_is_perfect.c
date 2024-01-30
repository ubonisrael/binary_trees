#include "binary_trees.h"
/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 0, If tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	height = binary_tree_height_left(tree);

	return (is_perfect(tree, height, 0));
}

/**
 * binary_tree_height_left - calculate the height of the left subtree.
 * @tree: pointer to the root node of the tree.
 * Return: height of the left subtree.
 */
int binary_tree_height_left(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height_left(tree->left) + 1);
}

/**
 * is_perfect - helper function to check if a binary tree is perfect.
 * @tree: pointer to the root node of the tree.
 * @height: height of the left subtree.
 * @depth: depth of the binary tree
 * Return: 1 if perfect, 0 otherwise.
 */
int is_perfect(const binary_tree_t *tree, int height, int depth)
{
	int l_val, r_val;

	if (!tree)
		return (height == 0);

	if (tree->left == NULL && tree->right == NULL)
		return (height == depth + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	l_val = is_perfect(tree->left, height, depth + 1);
	r_val = is_perfect(tree->right, height, depth + 1);

	return (l_val && r_val);
}
