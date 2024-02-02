#include "binary_trees.h"



/**
 * get_last_node - finds the last node in the last level of the heap
 * @root: double pointer to the root node of heap
 *
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	if (!root)
		return (NULL);

	/*use level order traversal to find the last node*/
	queue_t *front = NULL, *rear = NULL;
	heap_t *last_node = NULL;

	enqueue(&front, &rear, root);
	while (front)
	{
		last_node = dequeue(&front);

		if (last_node->left)
			enqueue(&front, &rear, last_node->left);
		if (last_node->right)
			enqueue(&front, &rear, last_node->right);
	}

	return (last_node);
}
/**
 * heapify_down - restores the Max Heap ordering after extraction
 * @root: pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
	if (!root)
		return;

	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	/*find the largest among root, left child, and right child*/
	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	/*if the largest is not the root, swap values and*/
	/*recursively heapify_down*/
	if (largest != root)
	{
		swap_values(&root->n, &largest->n);
		heapify_down(largest);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node;
	int root_value;

	if (!root || !*root)
		return (0);

	last_node = get_last_node(*root);
	root_value = (*root)->n;

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	/*replace root with last_node*/
	(*root)->n = last_node->n;

	/*find parent of last_node*/
	heap_t *parent = last_node->parent;

	/*remove last_node from its parent*/
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last_node);

	/*rebuild the Max Heap*/
	heapify_down(*root);

	return (root_value);
}
