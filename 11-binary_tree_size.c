#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size of the tree, or 0 on failure
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t right_size = 0;
	size_t left_size = 0;
	size_t tree_size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_size = binary_tree_size(tree->left);

	if (tree->right != NULL)
		right_size = binary_tree_size(tree->right);

	tree_size = right_size + left_size + 1;

	return (tree_size);
}
