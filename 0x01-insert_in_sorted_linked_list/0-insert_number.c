#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: head of the list.
 * @number: number to insert.
 * Return: the address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *aux;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL) {
		*head = new;

		return (new);
	}

	aux = *head;

	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			if (aux->n < number)
			{
				aux->next = new;
			}
			else
			{
				*head = new;
				new->next = aux;
			}

			return (new);
		}

		if (aux->next != NULL && aux->next->n >= number)
		{
			new->next = aux->next;
			aux->next = new;

			return (new);
		}

		aux = aux->next;
	}

	return (NULL);
}
