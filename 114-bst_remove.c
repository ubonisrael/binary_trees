#include "binary_trees.h"

/**
 * bst_remove - removes a node with a specific value from a Binary Search Tree.
 * @root: a pointer to the root node of the tree where the node
 * will be removed.
 * @value: the value to remove in the tree.
 * Return: a pointer to the new root node of the tree after removing
 * the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			root = NULL;
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			temp->parent = root->parent;
			free(root);
			root = NULL;
			return (temp);
		}

		temp = root->right;

		while (temp->left != NULL)
			temp = temp->left;

		/*copy the in-order successor's data to this node*/
		root->n = temp->n;

		/*delete the in-order successor*/
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
