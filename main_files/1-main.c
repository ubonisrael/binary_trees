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

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_print(root);
	printf("\n");
	binary_tree_insert_left(root->right, 128);
	binary_tree_insert_left(root, 54);
	binary_tree_insert_left(root->left->left, 50);
	binary_tree_insert_left(root->left->left, 40);
	binary_tree_insert_left(root->left->left, 20);
	binary_tree_print(root);
	return (0);
}
