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
	binary_tree_t *root, *node_t;
	size_t depth;

	root = binary_tree_node(NULL, 98), root->left = binary_tree_node(root, 12);
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
	depth = binary_tree_depth(root);
	printf("Depth of %d: %lu\n", root->n, depth);
	depth = binary_tree_depth(root->right);
	printf("Depth of %d: %lu\n", root->right->n, depth);
	depth = binary_tree_depth(root->left->right);
	printf("Depth of %d: %lu\n", root->left->right->n, depth);
	depth = binary_tree_depth(root->left->left);
	printf("Depth of %d: %lu\n", root->left->left->n, depth);
	depth = binary_tree_depth(root->right->left);
	printf("Depth of %d: %lu\n", root->right->left->n, depth);
	depth = binary_tree_depth(root->right->right);
	printf("Depth of %d: %lu\n", root->right->right->n, depth);
	node_t = root->right->right->right;
	depth = binary_tree_depth(node_t);
	printf("Depth of %d: %lu\n", node_t->n, depth);
	node_t = root->right->right->right->right;
	depth = binary_tree_depth(node_t);
	printf("Depth of %d: %lu\n", node_t->n, depth);
	return (0);
}
