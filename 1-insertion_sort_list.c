#include "sort.h"

/**
 * swap - swaps the nodes of a list
 * @list: head of the list
 * @a: first node
 * @b: second node
 * Return: void
 */

void swap(listint_t **list, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev)
		(*a)->prev->next = b;
	else
		*list = b;

	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - sorts a list using insertion sort
 * @list: points to head of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insertion = current->prev;

		while (insertion && current->n < insertion->n)
		{
			swap(list, &insertion, current);
			print_list(*list);
		}
	}
}
