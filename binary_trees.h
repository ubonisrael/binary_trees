#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* -------------------------- Note --------------------------- */
/* ----------------------------------------------------------- */
   /* Function that thier names start with underscore (_) */
   /* are copy function from other tasks in this project */
   /* but we can use them directly since we've no control */
   /* on the compiling command when the checkers runs the tests */
/* ----------------------------------------------------------- */
/* ----------------------------------------------------------- */



/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct queue_s - Queue element for level-order traversal
 *
 * @node: Pointer to a heap node
 * @next: Pointer to the next element in the queue
 */
struct queue_s
{
	heap_t *node;
	struct queue_s *next;
};

typedef struct queue_s queue_t;

/* ---- MAIN FUNCTIONS ---- */
/* task 0 to 8 */
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* task 9 to .. */
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);

int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_height_left(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, int height, int depth);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *_binary_tree_sibling(binary_tree_t *node);

binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second);
void binary_tree_levelorder(binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(binary_tree_t *tree);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* --------- BINARY SEARCH TREE FUNCTIONS ----------- */
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

/* -------------- AVL  FUnctions -------------------- */
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);

/* ---------- MAX BINARY HEAP FUNCTIONS ------------- */
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);

/* ---------------- HELPER FUNCTIONS ---------------- */
size_t _binary_tree_height(const binary_tree_t *tree);
size_t _binary_tree_size(const binary_tree_t *tree);
void b_delete(binary_tree_t *tr);
int is_duplicated(int *array, int value, size_t size);
int is_max_heap(const binary_tree_t *tree);

int bst_max_value(const binary_tree_t *tree);
int bst_min_value(const binary_tree_t *tree);
int is_bst_util(const binary_tree_t *tree, int min, int max);

int enqueue(queue_t **front, queue_t **rear, heap_t *node);
heap_t *dequeue(queue_t **front);
void free_queues(queue_t **front);
void heapify_up(heap_t *node);
void swap_values(int *a, int *b);


#endif
