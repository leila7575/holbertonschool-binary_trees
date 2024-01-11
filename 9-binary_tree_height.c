#include "binary_trees.h"

/**
 * binary_tree_height - mesures the height of a binary tree
 * @tree: pointer to root node of the tree
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
	{
		return (left_height + 1);
	}

	return  (right_height + 1);
}
