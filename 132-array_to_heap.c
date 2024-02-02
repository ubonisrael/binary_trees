#include "binary_trees.h"


/**
 * array_to_heap - builds a BST from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	binary_tree_t *root = NULL, *inserted = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* insert each element into the BST */
		inserted = heap_insert(&root, array[i]);

		/* if insertion fails.. */
		if (!inserted && !is_duplicated(array, array[i], size))
		{
			/* ..delete the already created nodes and return NULL */
			b_delete(root);
			return (NULL);
		}
	}
	return (root);
}
/**
 * b_delete - deletes an entire binary tr
 * @tr: is a pointer to the root node of the tr to delete
 * Return: void
 */
void b_delete(binary_tree_t *tr)
{
	if (tr == NULL)
		return;
	if (tr->left != NULL)
		b_delete(tr->left);
	if (tr->right != NULL)
		b_delete(tr->right);
	free(tr);
}

/**
 * is_duplicated - check if a numrical value in a array.
 * @array: pointer to the array we chack if it contiens the value.
 * @value: the value to be checked.
 * @size: number of elements in the array
 *Return: int _ 1 if it is in the array, 0 otherwise.
 */
int is_duplicated(int *array, int value, size_t size)
{
	int i, freq = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (value == array[i])
			freq++;
	}
	if (freq <= 1)
		return (0);
	return (1);
}
