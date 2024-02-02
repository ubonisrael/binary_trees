#include "binary_trees.h"
int _enqueue(queue_t **front, queue_t **rear, heap_t *node);

/**
 * _enqueue - enqueues a node into the queue
 * @front: pointer to the front of the queue
 * @rear: pointer to the rear of the queue
 * @node: pointer to the node to be enqueued
 * Return: 1 on success and 0 on failure.
 */
int _enqueue(queue_t **front, queue_t **rear, heap_t *node)
{
	queue_t *new_node;

	if (!node)
		return (0);
	new_node = malloc(sizeof(queue_t));
	if (!new_node)
		return (0);

	new_node->node = node;
	new_node->next = NULL;

	if (!*front)
	{
		*front = *rear = new_node;
	}
	else
	{
		(*rear)->next = new_node;
		*rear = new_node;
	}
	return (1);
}

/**
 * get_last_node - finds the last node in the last level of the heap
 * @root: double pointer to the root node of heap
 *
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	queue_t *front = NULL, *rear = NULL;
	heap_t *last_node = NULL;

	if (!root)
		return (NULL);

	_enqueue(&front, &rear, root);

	while (front)
	{
		last_node = dequeue(&front);

		if (last_node && last_node->left)
			_enqueue(&front, &rear, last_node->left);
		if (last_node && last_node->right)
			_enqueue(&front, &rear, last_node->right);
	}

	return (last_node);
}
/**
 * heapify_down - restores the MH ordering after extraction
 * @root: pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root, *right, *left;

	if (!root)
		return;

	right = root->right;
	left = root->left;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

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
	heap_t *last_node, *parent;
	int root_value;

	if (!root || !(*root))
		return (0);

	last_node = get_last_node(*root);
	root_value = (*root)->n;

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	/*replace root's value with last_node's value*/
	(*root)->n = last_node->n;

	parent = last_node->parent;

	/*detach last_node from its parent*/
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last_node);

	/* rebuild the max heap */
	heapify_down(*root);

	return (root_value);
}
