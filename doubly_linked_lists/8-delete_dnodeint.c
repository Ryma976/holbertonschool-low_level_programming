#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	while (temp)
	{
		if (i == index)
		{
			if (temp == *head)
			{
				*head = temp->next;
				if (*head)
					(*head)->prev = NULL;
			}
			else
			{
				temp->prev->next = temp->next;
				if (temp->next)
					temp->next->prev = temp->prev;
			}

			free(temp);
			return (1);
		}
		temp = temp->next;
		i++;
	}

	return (-1);
}
