#include "binary_trees.h"

int _is_avl_util(const binary_tree_t *tree, int min, int max);
binary_tree_t *_balance_tree(binary_tree_t *tree, binary_tree_t *tree_parent);
avl_t *_check_avl(binary_tree_t *node);

/**
  * find_min - finds the node with the minimum value in a AVL tree
  * @node: node to be perused for the minimum value
  * @min_node: node with the current value
  *
  * Description: In an AVL tree, much like a BST, the left children of
  * a node will always have the smaller. Hence, no need to go through the
  * right children.
  * Return: the node with the smallest value
  */

binary_tree_t *find_min(binary_tree_t *node, binary_tree_t *min_node)
{
	binary_tree_t *tmp, *min;

	if (node == NULL || min_node == NULL)
		return (NULL);
	min = node->n < min_node->n ? node : min_node;
	if (node->left)
	{
		tmp = find_min(node->left, min);
		min = tmp->n < min->n ? tmp : min;
	}
	return (min);
}

/**
  * set_parent_node - sets the child of a parent of a node to a new value
  * @node: pointer to node whose parent's pointer to it will be changed
  * @new_node: the new value of the parent's child
  * Return: void
  */

void set_parent_node(binary_tree_t *node, binary_tree_t *new_node)
{
	if (node == NULL || node->parent == NULL)
		return;
	if (node->n < node->parent->n)
		node->parent->left = new_node;
	else
		node->parent->right = new_node;
}

/**
  * avl_remove - removes a node from an AVL tree
  * @root: pointer to the root node of the tree for removing a node
  * @value: value to be removed from the tree
  * Return: a pointer to the new root node of the tree
  */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node, *tmp;

	node = root;
	if (node == NULL)
		return (NULL);
	if (value < node->n)
		return (avl_remove(node->left, value));
	if (value > node->n)
		return (avl_remove(node->right, value));

	/* at this stage, it means it is the current node */
	/* that needs to be removed */
	if (node->left == NULL && node->right == NULL)
	{
		tmp = node->parent;
		set_parent_node(node, NULL);
		free(node);
		return (_check_avl(tmp));
	}
	if (node->left != NULL && node->right == NULL)
	{
		tmp = node->left;
		tmp->parent = node->parent;
	}
	if (node->left == NULL && node->right == NULL)
	{
		tmp = node->right;
		tmp->parent = node->parent;
	}
	if (node->left != NULL && node->right != NULL)
	{
		tmp = find_min(node->right, node->right);
		set_parent_node(tmp, NULL);
		tmp->parent = node->parent;
		tmp->left = node->left;
		tmp->right = node->right;
		node->left->parent = tmp;
		if (node->right != NULL)
			node->right->parent = tmp;
	}
	set_parent_node(node, tmp);
	free(node);
	return (_check_avl(tmp));
}

/**
 * _check_avl - checks that the tree is a valid AVL tree,
 * if it isn't, it balances
 * @node: pointer to node to start from
 * Return: pointer to new root node
 */

avl_t *_check_avl(binary_tree_t *node)
{
	binary_tree_t *tmp, *tmp2;

	if (node == NULL)
		return (NULL);
	tmp = tmp2 = node;
	while (tmp != NULL)
	{
		if (_is_avl_util(tmp, INT_MIN, INT_MAX) == 0)
		{
			tmp = _balance_tree(tmp, tmp->parent);
		}
		tmp2 = tmp;
		tmp = tmp->parent;
	}
	return (tmp2);
}

/**
 * _balance_tree - rotates a node left or right to balance an unbalanced AVL
 * @tree: pointer to node to apply rotation
 * @tree_parent: pointer to node to tree's parent
 * Return: pointer to new root
 */

binary_tree_t *_balance_tree(binary_tree_t *tree, binary_tree_t *tree_parent)
{
	int lh, rh;
	binary_tree_t *new_root;

	lh = rh = 0;
	if (tree->left)
		lh = _binary_tree_height(tree->left) + 1;
	if (tree->right)
		rh = _binary_tree_height(tree->right) + 1;
	if (rh > lh)
	{
		if (binary_tree_balance(tree->right) <= 0)
		{
			new_root = binary_tree_rotate_left(tree);
		}
		else
		{
			new_root = binary_tree_rotate_right(tree->right);
			tree->right = new_root;
			new_root = binary_tree_rotate_left(tree);
		}
	}
	else
	{
		if (binary_tree_balance(tree->left) >= 0)
		{
			new_root = binary_tree_rotate_right(tree);
		}
		else
		{
			new_root = binary_tree_rotate_left(tree->left);
			tree->left = new_root;
			new_root = binary_tree_rotate_right(tree);
		}
	}
	if (tree_parent)
	{
		if (new_root->n > (tree_parent)->n)
			(tree_parent)->right = new_root;
		else
			(tree_parent)->left = new_root;
		new_root->parent = (tree_parent);
	}
	else
		new_root->parent = tree_parent;
	tree = new_root;
	return (tree);
}

/**
 * _is_avl_util - helper function to check if a binary tree is a valid AVL
 * @tree: pointer to the root node of the tree
 * @min: minimum allowed value for the current node
 * @max: maximum allowed value for the current node
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int _is_avl_util(const binary_tree_t *tree, int min, int max)
{
	int bal, l_is_vld, r_is_vld;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	bal = binary_tree_balance(tree);
	if (bal < -1 || bal > 1)
		return (0);

	l_is_vld = _is_avl_util(tree->left, min, tree->n);
	r_is_vld = _is_avl_util(tree->right, tree->n, max);

	return (l_is_vld && r_is_vld);
}
