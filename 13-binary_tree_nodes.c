#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts the nodes with at least
 * 1 child in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * A NULL pointer is not a node
 * Return: 0, If tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_1 = 0, count_2 = 0;

	/* return 0 is the node tree is NULL */
	/* or both sides of the node arre NULL */
	if (!tree || (!tree->left && !tree->right))
		return (0);

	count_1 = binary_tree_nodes(tree->left);
	count_2 = binary_tree_nodes(tree->right);
	return (count_1 + count_2 + 1);
}

/*size_t binary_tree_nodes(const binary_tree_t *tree)*/
/*{*/
	/*binary_tree_t *right, *left;*/

	/*if (!tree)*/
		/*return (0);*/

	/*if (tree->left || tree->right)*/
	/*{*/
		/*left = tree->left;*/
		/*right = tree->right;*/
		/*return (binary_tree_nodes(left) + binary_tree_nodes(right) + 1);*/
	/*}*/
	/*return (0);*/

/*}*/
