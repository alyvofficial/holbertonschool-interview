#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a node in a sorted singly linked list.
 * @head: head of the linked list.
 * @number: number to insert.
 * Return: address of the new node or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    new->next = current->next;
    current->next = new;

    return (new);
}