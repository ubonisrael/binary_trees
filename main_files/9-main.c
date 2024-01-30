#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	size_t height;

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

	height = binary_tree_height(root);
	printf("Height from %d: %lu\n", root->n, height);
	height = binary_tree_height(root->right);
	printf("Height from %d: %lu\n", root->right->n, height);
	height = binary_tree_height(root->left->right);
	printf("Height from %d: %lu\n", root->left->right->n, height);
	height = binary_tree_height(root->right->right->right);
	printf("Height from %d: %lu\n", root->right->right->right->n, height);
	height = binary_tree_height(root->right->right->left->right);
	printf("Height from %d: %lu\n", root->right->right->left->right->n, height);
	return (0);
}
