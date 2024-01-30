#include "binary_trees.h"

binary_tree_t **create_queue(binary_tree_t *tree);
void add_to_queue(binary_tree_t **queue, binary_tree_t *node, int *pos);
binary_tree_t *pop_queue(binary_tree_t **queue, int *pos);
/**
  * binary_tree_levelorder - goes through a binary tree using level-order
  * traversal
  * @tree: pointer to the root of the tree
  * @func: pointer to function to call for each node
  * Return: void
  */

void binary_tree_levelorder(binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	binary_tree_t *tmp;
	int front, rear;

	if (tree == NULL)
		return;
	queue = create_queue(tree);
	if (queue == NULL)
		return;
	front = rear = 0;
	tmp = tree;
	while (tmp && front <= rear)
	{
		func(tmp->n);

		if (tmp->left)
			add_to_queue(queue, tmp->left, &rear);
		if (tmp->right)
			add_to_queue(queue, tmp->right, &rear);

		tmp = pop_queue(queue, &front);
	}
	free(queue);
}

/**
  * create_queue - creates a queue for storing nodes in a binary tree
  * @tree:  pointer to binary tree
  * Return: the pointer to the create queue if successful, else NULL
  */

binary_tree_t **create_queue(binary_tree_t *tree)
{
	binary_tree_t **queue;
	int height;

	height = binary_tree_height(tree);
	queue = malloc(sizeof(binary_tree_t *) * (height + 1));

	if (queue == NULL)
		return (NULL);
	return (queue);
}

/**
  * add_to_queue - adds a node's children to a queue
  * @queue: queue to be used
  * @node: node to be added
  * @pos: position in the queue to be added
  * Return: void
  */

void add_to_queue(binary_tree_t **queue, binary_tree_t *node, int *pos)
{
	queue[*pos] = node;
	(*pos)++;
}

/**
  * pop_queue - removes first element from queue
  * @queue: queue to be used
  * @pos: position of first element
  * Return: on success, a binary tree node
  */

binary_tree_t *pop_queue(binary_tree_t **queue, int *pos)
{
	binary_tree_t *node;

	node = queue[*pos];
	(*pos)++;
	return (node);
}

/**
  * binary_tree_height - a function that measures the height of a binary tree
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (!tree)
		return (0);

	/* the height of the left branch */
	if (tree->left)
		lheight = binary_tree_height(tree->left) + 1;

	/* the height of the right branch */
	if (tree->right)
		rheight = binary_tree_height(tree->right) + 1;

	/* check  the heigher height between */
	/* the two branches (left or right) */
	if (lheight > rheight)
		return (lheight);
	return (rheight);
}
