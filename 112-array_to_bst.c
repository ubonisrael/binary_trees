#include "binary_trees.h"
void _binary_tree_delete(binary_tree_t *tree);

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	binary_tree_t *root = NULL, *inserted = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* insert each element into the BST */
		inserted = bst_insert(&root, array[i]);

		/* if insertion fails.. */
		if (!inserted)
		{
			/* ..delete the already created nodes and return NULL */
			_binary_tree_delete(root);
			return (NULL);
		}
	}
	return (root);
}

/**
 * _binary_tree_delete - deletes an entire binary tree
 * @tree: is a pointer to the root node of the tree to delete
 * Return: void
 */

void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_delete(tree->left);
	if (tree->right != NULL)
		binary_tree_delete(tree->right);
	free(tree);
}
