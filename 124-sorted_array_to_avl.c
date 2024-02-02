#include "binary_trees.h"

avl_t *create_sort_arr_util(avl_t *tree, binary_tree_t *parent_node,
		int *arr, int start, int end);

/**
  * sorted_array_to_avl - builds an AVL tree from an array
  * @array: pointer to the first element of the array to be converted
  * @size: number of element in the array
  * Return: pointer to the root node of the created AVL tree or NULL on failure
  */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	return (create_sort_arr_util(root, NULL, array, 0, size - 1));
}

/**
  * create_sort_arr_util - helps to create an avl tree from a sorted array
  * @tree: pointer to pointer to root node
  * @parent_node: pointer to parent node of node to be created
  * @arr: pointer to array
  * @start: start position of array
  * @end: end position of array
  * Return: root node of avl tree
  */

avl_t *create_sort_arr_util(avl_t *tree, binary_tree_t *parent_node,
		int *arr, int start, int end)
{
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	tree = binary_tree_node(parent_node, arr[mid]);
	if (tree == NULL)
		return (NULL);
	tree->left = create_sort_arr_util(tree->left, tree, arr, start, mid - 1);
	tree->right = create_sort_arr_util(tree->right, tree, arr, mid + 1, end);
	return (tree);
}
