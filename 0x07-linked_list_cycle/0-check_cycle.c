#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to the head of the list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list;

	if (list == NULL)
		return (0);

	while (1)
	{
		slow = slow->next;

		if (fast->next != NULL)
			fast = fast->next->next;
		else
			return (0);

		if (slow == NULL || fast == NULL)
			return (0);

		if (slow == fast)
			return (1);
	}
}
