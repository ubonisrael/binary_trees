#include "binary_trees.h"

/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: pointer to first node
  * @second: pointer to second node
  * Return: pointer to common ancestor
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_ancestor = first->parent;
	binary_tree_t *second_ancestor = second->parent;
	size_t f_depth = binary_tree_depth(first_ancestor);
	size_t s_depth = binary_tree_depth(second_ancestor);

	while (first_ancestor && second_ancestor)
	{
		/* Ensure that both nodes are on the same level */
		/* If the first node's depth is smaller*/
		/* it means it's higher up the tree, vice versa */
		if (f_depth < s_depth)
		{
			while (f_depth < s_depth)
			{
				second_ancestor = second_ancestor->parent;
				s_depth = binary_tree_depth(second_ancestor);
			}
		}
		if (f_depth > s_depth)
		{
			while (f_depth > s_depth)
			{
				first_ancestor = first_ancestor->parent;
				f_depth = binary_tree_depth(first_ancestor);
			}
		}
		if (first_ancestor == second_ancestor)
			return (first_ancestor);
		first_ancestor = first_ancestor->parent;
		second_ancestor = second_ancestor->parent;
	}
	return (NULL);
}

/**
  * binary_tree_depth - a function that measures the depth of
  * a node in a binary tree
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth = binary_tree_depth(tree->parent) + 1;

	return (depth);
}
