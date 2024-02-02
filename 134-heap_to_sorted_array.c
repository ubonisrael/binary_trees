#include "binary_trees.h"
/**
 * heap_to_sorted_array - converts a Binary Max Heap to a
 * sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to the sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, size_heap;

	if (!heap)
		return (NULL);

	size_heap = binary_tree_size(heap);
	if (!size_heap)
		return (NULL);

	array = malloc(size_heap * sizeof(int));
	if (!array)
	{
		free(array);
		return (NULL);
	}

	*size = 0;
	for (i = 0; i < size_heap; i++, (*size)++)
		array[i] = heap_extract(&heap);
	return (array);
}


/**
  * binary_tree_size - a function that measures the size of a binary tree
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (tree->left)
		count = count + binary_tree_size(tree->left);

	if (tree->right)
		count = count + binary_tree_size(tree->right);

	return (count + 1);
}
