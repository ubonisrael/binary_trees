#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: size of the array
 * Return: pointer to root node of AVL tree or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL, *inserted = NULL;
	size_t i = 0;

	if (array == NULL || size == 0)
		return (NULL);

	printf("Inserting nodes:\n");

	for (; i < size; i++)
	{
		printf("Inserting value %d\n", array[i]);
		inserted = avl_insert(&root, array[i]);
		if (!inserted)
		{
			fprintf(stderr, "Failed to insert value %d\n", array[i]);
			return (NULL);
		}
		printf("Inserted value %d, tree after insertion:\n", array[i]);
		binary_tree_print(root);
	}

	printf("Finished inserting nodes, final tree:\n");
	binary_tree_print(root);

	return (root);
}

