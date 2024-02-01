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
	binary_tree_t *first_ancestor, *second_ancestor;
	size_t f_depth, s_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	f_depth = binary_tree_depth(first);
	s_depth = binary_tree_depth(second);
	first_ancestor = first->parent;
	second_ancestor = second->parent;

	if (f_depth < s_depth)
	{
		while (f_depth < s_depth)
		{
			if (second_ancestor == first)
				return (second_ancestor);
			s_depth = binary_tree_depth(second_ancestor);
			second_ancestor = second_ancestor->parent;
		}
	}
	if (f_depth > s_depth)
	{
		while (f_depth > s_depth)
		{
			if (first_ancestor == second)
				return (first_ancestor);
			f_depth = binary_tree_depth(first_ancestor);
			first_ancestor = first_ancestor->parent;
		}
	}
	while (first_ancestor && second_ancestor)
	{
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
