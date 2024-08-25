#include "algorithms.h"

// INSERTION SORT
// performs in-place sorting of singly linked lists, always finding next element that is not in position and putting it to the right place into sorted subsequence of elements starting from the head
// keeps the position of the end of the sorted list
// does not handle if there are duplicates in the list
// @returns 1 if list is sorted, 0 if error occurred
int insertion_sort(s_list **head)
{
	s_list *sorted_end;
	s_list *current;
	s_list *temp;

	if (!head || !*head) // if head pointer or the actual head node are empty return NULL
		return (0);
	if (!(*head)->next) // if list only has one element return 1 as it is already sorted
		return (1);
	sorted_end = *head;  // Start with the first node as the sorted part
	current = (*head)->next; // The node to insert into the sorted part

	while (current != NULL)
	{
		if (*(int *)current->content < *(int *)sorted_end->content) // if our element is smaller than the end of the sorted part, we have to put it into the correct position
		{
			// remove 'current' from its position to keep the connections of the list intact
			// so link the element right after sorted_end, which was our current, to the one after current
			sorted_end->next = current->next;
			// only in case that current is smaller than head of the list insert it at the beginning of the list
			if (*(int *)current->content < *(int *)(*head)->content)
			{
				current->next = *head;
				*head = current;
			}
			// in other cases we must find its place by iterating from the start of the list until we find element that is the last element smaller than our current, which is stored in our temp
			else
			{
				// iterating over the list
				temp = *head;
				while (temp->next != current && *(int *)temp->next->content < *(int *)current->content)
					temp = temp->next;
				// temp is now set to the last element smaller than our current, so current will be linked after it
				// setting the current element into its correct position
				current->next = temp->next;
				temp->next = current;
			}
			current = sorted_end->next; // update the current element for next iteration to be the one after our sorted end
		}
		else // otherwise the current element is bigger than the sorted end thus becomes the new sorted end
		{
			sorted_end = current;
			current = current->next; // update our current element for next ietartion to be the one after the current
		}
	}
	return 1;
}

// EXAMPLE PROGRAM:
// int main(void)
// {
// 	int *c1, *c2, *c3, *c4, *c5, *c6;
// 	s_list *lst = NULL;  // Initialize the list

// 	// creating new list
// 	c1 = malloc(sizeof(int));
// 	if (!c1)
// 	{
// 		ft_lstclear(&lst);
// 		return 1;
// 	}
// 	*c1 = 26;
// 	ft_lstadd_back(&lst, ft_lstnew((void *)c1));

// 	c2 = malloc(sizeof(int));
// 	if (!c2)
// 	{
// 		ft_lstclear(&lst);
// 		return 1;
// 	}
// 	*c2 = 100;
// 	ft_lstadd_back(&lst, ft_lstnew((void *)c2));

// 	c3 = malloc(sizeof(int));  // Allocate space for the integer
// 	if (!c3)
// 	{
// 		ft_lstclear(&lst);
// 		return 1;
// 	}
// 	*c3 = 31;
// 	ft_lstadd_back(&lst, ft_lstnew((void *)c3));

// 	c4 = malloc(sizeof(int));  // Allocate space for the integer
// 	if (!c4)
// 	{
// 		ft_lstclear(&lst);
// 		return 1;
// 	}
// 	*c4 = -8;
// 	ft_lstadd_back(&lst, ft_lstnew((void *)c4));

// 	c5 = malloc(sizeof(int));  // Allocate space for the integer
// 	if (!c5)
// 	{
// 		ft_lstclear(&lst);
// 		return 1;
// 	}
// 	*c5 = 1;
// 	ft_lstadd_back(&lst, ft_lstnew((void *)c5));

// 	c6 = malloc(sizeof(int));  // Allocate space for the integer
// 	if (!c6)
// 	{
// 		ft_lstclear(&lst);
// 		return 1;
// 	}
// 	*c6 = 0;
// 	ft_lstadd_back(&lst, ft_lstnew((void *)c6));

// 	// print list
// 	printf("List at start: ");
// 	print_list(lst);
// 	// perform sorting
// 	insertion_sort(&lst);
// 	printf("List at end: ");
// 	print_list(lst);
// 	ft_lstclear(&lst);  // Free all nodes and their content
// }
