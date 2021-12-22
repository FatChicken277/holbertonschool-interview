#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - verify if a linked list is a palindrome
 * @head: pointer to the head node of the list to reverse
 * Return: 1 if the list is palindrome 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	int len = 0, i = 0, aux_array[10000];
	listint_t *aux_head = *head;

	if (head == NULL || *head == NULL)
		return (1);

	for (len = 0; aux_head != NULL; len++)
	{
		aux_array[len] = aux_head->n;
		aux_head = aux_head->next;
	}

	if (len == 1)
		return (1);

	aux_head = *head;

	for (i = 0; aux_head != NULL; i++, len--)
	{
		if (aux_head->n != aux_array[len - 1])
			return (0);

		aux_head = aux_head->next;
	}

	return (1);
}
