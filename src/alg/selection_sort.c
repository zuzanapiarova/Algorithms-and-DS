#include "algorithms.h"

// SELECTION SORT
// keep two pointers: one that points to current set minumum and one for the current item we are at (plus keep a pointer to the element we started from - first iteration first element, second iteration second element, etc.)
// current item pointer looks at all elements of the list and compares them to the current minimum pointer, when current item is smaller than current minimum, current minimum pointer is set here
// when entire list is iterated, we swap the current minimum with the position we started from in this iteration (first iteration first element, second iteration second element, etc.)
// list is being sorted form the start - first iteration places smallest item on correct spot, second iteration the second smallest item etc.
// this algorithm starts to build the sorted part from the left, but it can build the sorted part form te start and look for biggest elements
// set first element as the minimum, find the true minimum by iteration entire list, and swap this newfound minimum with the element we started from
int selection_sort(s_list **head)
{
	s_list *current;
	s_list *min;
	s_list *to_swap;
	int i;
	int size;

	if (!head || !*head)
		return (0);
	if (!(*head)->next)
		return (1);

	i = 1;
	size = ft_lstsize(*head);
	while (i < size)
	{
		// set all pointers to correct element after each iteration - to the element right after the sorted part of the array
		current = get_nth_element(*head, i);
		min = current;
		to_swap = current;
		while (current)
		{
			if (*(int *)current->content < *(int *)min->content)
				min = current;
			if (current->next == NULL)
				break ;
			current = current->next;
		}
		// swap the to_swap which is the first element after the unsorted part with min to start putting smallest elements form the start
		swap_nodes(head, to_swap, min);
		i++;
	}
	return 1;
}
