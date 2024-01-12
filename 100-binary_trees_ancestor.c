#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *anc_first;
	binary_tree_t *anc_second;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second ||
	first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	anc_first = binary_trees_ancestor(first->parent, second);
	anc_second = binary_trees_ancestor(first, second->parent);
	if (anc_first &&
	anc_second &&
	anc_first != anc_second)
		return ((binary_tree_t *)first);
	if (anc_first != NULL)
		return (anc_first);
	return (anc_second);
}
