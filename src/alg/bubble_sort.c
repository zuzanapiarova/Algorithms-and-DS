#include "algorithms.h"

int bubble_sort(s_list **head)
{
	s_list *current; // current ends up as the biggest value of the list and bubbles up to the end of the list
	s_list *prev;
	s_list *sorted_start;

	if (!head || !*head)
		return (0);
	if (!(*head)->next)
		return (1);
	current = *head;
	sorted_start = NULL;
	prev = NULL;

	// iterate until the `sorted_start` pointer reaches the head
	while (sorted_start != *head)
	{
		current = *head;
		prev = NULL;
		// Iterate through the list until the last sorted element
		while (current->next != sorted_start)
		{
			// in case when our element is bigger thn its next element, we swap them, moving current to next element, thus we have to also move the prev to the next element
			if (*(int *)current->content > *(int *)current->next->content)
			{
				swap_adjacent(head, prev, current);
				if (prev == NULL)
					prev = *head;
				else
					prev = prev->next;
			}
			else // Move `prev` and `current` forward if no swap is needed
			{
				prev = current;
				current = current->next;
			}
 		}
		// Move `sorted_start` one node back (= to current) as the last element is now sorted so the sorted_start of unsorted list is one before
		sorted_start = current;
	}
	return (1);
}
