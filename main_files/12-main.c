#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	size_t size;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);
	root->right->right->right = binary_tree_node(
			root->right->right, 52);
	root->right->right->right->left = binary_tree_node
		(root->right->right->right, 53);
	root->right->right->left = binary_tree_node(root->right->right, 51);
	root->right->right->left->left = binary_tree_node
		(root->right->right->left, 50);
	root->right->right->left->right = binary_tree_node
		(root->right->right->left, 54);
	root->right->right->right->right = binary_tree_node
		(root->right->right->right, 529);

	binary_tree_print(root);

	size = binary_tree_leaves(root);
	printf("Size of %d: %lu\n", root->n, size);
	size = binary_tree_leaves(root->right);
	printf("Size of %d: %lu\n", root->right->n, size);
	size = binary_tree_leaves(root->left->right);
	printf("Size of %d: %lu\n", root->left->right->n, size);
	size = binary_tree_leaves(root->right->right->right->right);
	printf("Size of %d: %lu\n", root->right->right->right->right->n, size);
	size = binary_tree_leaves(root->right->right->right);
	printf("Size of %d: %lu\n", root->right->right->right->n, size);
	size = binary_tree_leaves(root->right->right);
	printf("Size of %d: %lu\n", root->right->right->n, size);
	return (0);
}

