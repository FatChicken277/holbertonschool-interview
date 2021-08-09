#include "search.h"

/**
 * linear_skip - use linear skip to find a item in a list
 * @list: pointer to the head of the list
 * @value: value to search
 * Return: position of list item
 **/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *e_lane, *prev;

	if (list == NULL)
		return (NULL);

	e_lane = list->express;
	prev = list;

	for (; e_lane; e_lane = e_lane->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", e_lane->index, e_lane->n);
		if (!e_lane->express || e_lane->n >= value)
		{
			if (!e_lane->express && e_lane->n < value)
			{
				for (prev = e_lane; e_lane->next; e_lane = e_lane->next)
					;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				   prev->index, e_lane->index);
			for (; prev; prev = prev->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
				if (prev->n > value)
					return (NULL);
				if (prev->n == value)
					return (prev);
			}
			break;
		}
		prev = e_lane;
	}

	return (NULL);
}
