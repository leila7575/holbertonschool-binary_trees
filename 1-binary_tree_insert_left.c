#include "binary_trees.h"

/**
 * binary_tree_insert_left- insert left-child node
 * @parent: parent to insert
 * @value: value of new node
 *
 * Return: pointer to created node or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!parent || !new)
	{
		free(new);
		return (NULL);
	}

	new->parent = parent;
	new->n = value;
	new->right = NULL;
	new->left = NULL;

	if (parent->left)
	{
		new->left = parent->left;
		new->left->parent = new;
	}

	parent->left = new;
	return (new);
}
