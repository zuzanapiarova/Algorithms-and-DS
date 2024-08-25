#include "algorithms.h"

bool check_ordered(s_list *lst)
{
	if (!lst)
		return true;
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return false;
		lst = lst->next;
	}
	return true;
}

s_list	*get_nth_element(s_list *lst, int pos)
{
	if (!lst || pos <= 0)
		return (NULL);
	while (lst->next != NULL && pos > 1)
	{
		lst = lst->next;
		pos--;
	}
	return (lst);
}

void swap_adjacent(s_list **head, s_list *prev, s_list *current)
{
	s_list *next_node;

	if (!current || !current->next)
		return;
	next_node = current->next;
	if (prev)
		prev->next = next_node; // move prev one node upwards
	else
		*head = next_node; // if there's no previous node, update the head
	// swap current and next_node
	current->next = next_node->next;
	next_node->next = current;
}
