#include "binary_trees.h"
void power_of_red(void);

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current, *tmp;
	queue_t *front = NULL, *rear = NULL;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		if (!*root)
		{
			free_queues(&front);
		}
		return (*root);
	}

	if (!enqueue(&front, &rear, *root))
	{
		free_queues(&front);
		return (NULL);
	}
	while (front)
	{
		current = dequeue(&front);
		if (value == current->n)
		{
			free_queues(&front);
			return (current);
		}
		if (!current->left)
		{
			new_node = binary_tree_node(current, value);
			if (!new_node)
			{
				free_queues(&front);
				return (NULL);
			}

			current->left = new_node;
			tmp = heapify_up(new_node);
			free_queues(&front);
			return (tmp);
		}
		else if (!enqueue(&front, &rear, current->left))
		{
			free_queues(&front);
			return (NULL);
		}
		if (!current->right)
		{
			new_node = binary_tree_node(current, value);
			if (!new_node)
			{
				free_queues(&front);
				return (NULL);
			}

			current->right = new_node;
			tmp = heapify_up(new_node);
			free_queues(&front);
			return (tmp);
		}
		else if (!enqueue(&front, &rear, current->right))
		{
			free_queues(&front);
			return (NULL);
		}
	}
	free_queues(&front);

	return (NULL);
}


/**
 * enqueue - enqueues a node into the queue
 * @front: pointer to the front of the queue
 * @rear: pointer to the rear of the queue
 * @node: pointer to the node to be enqueued
 * Return: 1 on success and 0 on failure.
 */
int enqueue(queue_t **front, queue_t **rear, heap_t *node)
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
 * dequeue - dequeues a node from the queue
 * @front: pointer to the front of the queue
 *
 * Return: pointer to the dequeued node
 */
heap_t *dequeue(queue_t **front)
{
	heap_t *node;
	queue_t *temp;

	if (!*front)
		return (NULL);

	temp = *front;
	node = temp->node;
	*front = (*front)->next;
	free(temp);

	return (node);
}

/**
 * heapify_up - restores the Max Heap ordering after insertion
 * @node: pointer to the newly inserted node
 * Return: pointer to newly inserted node
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *current = node;

	while (current->parent && current->n > current->parent->n)
	{
		swap_values(&current->n, &current->parent->n);
		current = current->parent;
	}
	return (current);
}

/**
 * free_queues - frees all nodes in the queue
 * @front: pointer to the front of the queue
 */
void free_queues(queue_t **front)
{
	queue_t *temp;

	while (*front)
	{
		temp = *front;
		*front = (*front)->next;
		free(temp);
	}
}
/**
  * swap_values - swaps the values of two integers
  * @a: pointer to the first integer
  * @b: pointer to the second integer
  */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
