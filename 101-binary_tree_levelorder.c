#include "binary_trees.h"

/**
 * get_binary_tree_height - mesures the height of a binary tree
 * @tree: pointer to root node of the tree
 * Return: 0 if tree is NULL
 */
static size_t get_binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = get_binary_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = get_binary_tree_height(tree->right) + 1;

	if (left_height >= right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_recursivelevelorder - function using levelorder traversal
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_recursivelevelorder(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
	{
		return;
	}

	if (level == 1)
		func (tree->n);
	else if (level > 1)
	{
		binary_tree_recursivelevelorder (tree->left, func, level - 1);
		binary_tree_recursivelevelorder (tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - function using levelorder traversal
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i;
	size_t h = get_binary_tree_height(tree);

	if (tree == NULL || func == NULL)
	{
		return;
	}

	for (i = 1; i <= h; i++)
		binary_tree_recursivelevelorder(tree, func, i);
}



