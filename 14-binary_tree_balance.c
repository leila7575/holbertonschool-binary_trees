#include "binary_trees.h"

/**
 * binary_tree_height - mesures the height of a binary tree
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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to root node
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
        int r_height = 0;
        int l_height = 0;

        if (tree == NULL)
                return (0);

        if (tree->right != NULL)
                r_height = get_binary_tree_height(tree->right);
        else
                r_height = -1;

        if (tree->left != NULL)
                l_height = get_binary_tree_height(tree->left);
        else
                l_height = -1;

        return (r_height - l_height);
}

