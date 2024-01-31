#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert in the BST
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	/* if the tree pointer by double pointer is empty, we create a new */
	/* a new node as the root. */
	if ((*tree) == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	/* we go left if the value is less then the current node's value. */
	if (value < (*tree)->n)
	{
		/* if there is no left child, we create one. */
		if (!(*tree)->left)
		{
			(*tree)->left =  binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		/* if there is a left child, we continue recursing! */
		else
			return (bst_insert(&((*tree)->left), value));
	}
	/* we go right if the value is greater then the current node's value. */
	else if (value > (*tree)->n)
	{
		/* if there is no right child, we create one. */
		if (!(*tree)->right)
		{
			(*tree)->right =  binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		/* if there is a right child, we continue recursing! */
		else
			return (bst_insert(&((*tree)->right), value));
	}
	/* if the value does existe, "value == (*tree)->left/right",*/
	/* we ignore it! */
	return (NULL);
}
