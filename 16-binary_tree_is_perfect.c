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
 *binary_tree_is_perfect - checks if a binary tree is perfect
 *@tree: pointer to root node
 *Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL  && tree->right == NULL)
		return (1);
	if (tree->left == NULL  || tree->right == NULL)
		return (0);
	if (get_binary_tree_height(tree->left) != get_binary_tree_height(tree->right))
		return (0);
	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}
