#include <stdio.h>
#include "lists.h"

/**
 * reverseList - reverse a linked list.
 * @head: pointer to the head node of the list to reverse
 */
void reverseList(listint_t **head)
{
	listint_t *prevNode, *curNode;

	if (*head != NULL)
	{
		prevNode = *head;
		curNode = (*head)->next;
		*head = (*head)->next;

		prevNode->next = NULL;

		while (*head != NULL)
		{
			*head = (*head)->next;
			curNode->next = prevNode;

			prevNode = curNode;
			curNode = *head;
		}

		*head = prevNode;
	}
}

/**
 * is_palindrome - verify if a linked list is a palindrome
 * @head: pointer to the head node of the list to reverse
 * Return: 1 if the list is palindrome 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	listint_t *reversed = *head;

	reverseList(&reversed);

	while (*head != NULL)
	{
		if (reversed->n != (*head)->n)
			return (0);

		reversed = reversed->next;
		*head = (*head)->next;
	}

	return (1);
}
