#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * reverse_list - reverse a linked list in-place
 * @head: pointer to the head of the list
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head);

/**
 * is_palindrome - identify if a singly linked list is palindrome
 * @head: head of listint_t
 * Return: 1 if it is palindrome else 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *prev_slow, *mid, *second_half;
    int is_palindrome = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    slow = fast = *head;
    prev_slow = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != NULL)  /* Odd number of nodes, skip the middle one */
        slow = slow->next;

    mid = slow;
    second_half = reverse_list(&mid);

    while (second_half != NULL)
    {
        if ((*head)->n != second_half->n)
        {
            is_palindrome = 0;
            break;
        }

        *head = (*head)->next;
        second_half = second_half->next;
    }

    /* Restore the original list */
    reverse_list(&mid);
    if (prev_slow != NULL)
        prev_slow->next = mid;
    else
        *head = mid;

    return is_palindrome;
}

/**
 * reverse_list - reverse a linked list in-place
 * @head: pointer to the head of the list
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL, *current = *head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}
