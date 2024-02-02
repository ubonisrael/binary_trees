#include "binary_trees.h"

/**
  * array_to_avl - builds an AVL tree from an array
  * @array: pointer to the first element of the array to be converted
  * @size: size of the array
  * Return: pointer to root node of AVL tree or NULL on failure
  */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i = 0;

	if (array == NULL)
		return (NULL);
	for (; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
