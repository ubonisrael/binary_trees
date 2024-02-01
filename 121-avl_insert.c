#include "binary_trees.h"

binary_tree_t *balance_tree(binary_tree_t *tree, binary_tree_t *tree_parent);
avl_t *check_avl(binary_tree_t *node);
int is_avl_util(const binary_tree_t *tree, int min, int max);
int _binary_tree_is_avl(const binary_tree_t *tree);
avl_t *_avl_insert_util(avl_t **tree, int value, avl_t **root);

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root of the AVL for inserting value
 * @value: value to store in newly created node
 * Return: pointer to newly created node or NULL if successful
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	return (_avl_insert_util(tree, value, tree));
}

/**
 * _avl_insert_util - inserts a value in an AVL Tree
 * @tree: double pointer to root of the AVL for inserting value
 * @value: value to store in newly created node
 * @root: double pointer to original root of the AVL for inserting value
 * Return: pointer to newly created node or NULL if successful
 */

avl_t *_avl_insert_util(avl_t **tree, int value, avl_t **root)
{
	binary_tree_t *node;
	avl_t *tmp;

	if ((*tree) == NULL)
	{
		node = binary_tree_node((*tree), value);
		(*tree) = node;
		return (node);
	}
	if (value == ((*tree)->n))
		return (NULL);
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			node = binary_tree_node((*tree), value);
			(*tree)->left = node;
			tmp = check_avl(node);
			if (tmp->parent == NULL)
			{
				*root = tmp;
			}
			return (node);
		}
		return (_avl_insert_util(&(*tree)->left, value, root));
	}

	if ((*tree)->right == NULL)
	{
		node = binary_tree_node((*tree), value);
		(*tree)->right = node;
		tmp = check_avl(node);
		if (tmp->parent == NULL)
		{
			*root = tmp;
		}
		return (node);
	}
	return (_avl_insert_util(&(*tree)->right, value, root));
}

/**
 * check_avl - checks that the tree is a valid AVL tree,
 * if it isn't, it balances
 * @node: pointer to node to start from
 * Return: pointer to new root node
 */

avl_t *check_avl(binary_tree_t *node)
{
	binary_tree_t *tmp, *tmp2;

	if (node == NULL)
		return (NULL);
	tmp = tmp2 = node;
	while (tmp != NULL)
	{
		if (_binary_tree_is_avl(tmp) == 0)
		{
			tmp = balance_tree(tmp, tmp->parent);
		}
		tmp2 = tmp;
		tmp = tmp->parent;
	}
	return (tmp2);
}

/**
 * balance_tree - rotates a node left or right to balance an unbalanced AVL
 * @tree: pointer to node to apply rotation
 * @tree_parent: pointer to node to tree's parent
 * Return: pointer to new root
 */

binary_tree_t *balance_tree(binary_tree_t *tree, binary_tree_t *tree_parent)
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
 * is_avl_util - helper function to check if a binary tree is a valid AVL
 * @tree: pointer to the root node of the tree
 * @min: minimum allowed value for the current node
 * @max: maximum allowed value for the current node
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_avl_util(const binary_tree_t *tree, int min, int max)
{
	int bal, l_is_vld, r_is_vld;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	bal = binary_tree_balance(tree);
	if (bal < -1 || bal > 1)
		return (0);

	l_is_vld = is_avl_util(tree->left, min, tree->n);
	r_is_vld = is_avl_util(tree->right, tree->n, max);

	return (l_is_vld && r_is_vld);
}

/**
 * _binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if true, else 0
 */

int _binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_util(tree, INT_MIN, INT_MAX));
}
