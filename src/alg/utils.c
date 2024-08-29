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
	if (!lst || pos < 1)
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

void swap_nodes(s_list** head, s_list* n1, s_list* n2)
{
    s_list *prevNode1 = NULL;
	s_list *prevNode2 = NULL;
	s_list *node1 = *head;
	s_list *node2 = *head;
	s_list *temp = NULL;

    if(head == NULL) // return if list is empty
        return;
    if(n1 == n2) // if n1 and n2 are equal, do nothing
        return;

    //Search for node1 and node2
    while(node1 != NULL && *(int *)node1->content != *(int *)n1->content)
	{
        prevNode1 = node1;
        node1 = node1->next;
	}
    while(node2 != NULL && *(int *)node2->content != *(int *)n2->content)
	{
        prevNode2 = node2;
        node2 = node2->next;
    }

    if(node1 != NULL && node2 != NULL)
	{
        //If previous node to node1 is not null then, it will point to node2
        if(prevNode1 != NULL)
            prevNode1->next = node2;
        else
            *head  = node2;
        //If previous node to node2 is not null then, it will point to node1
        if(prevNode2 != NULL)
            prevNode2->next = node1;
        else
            *head  = node1;
        //Swaps the next nodes of node1 and node2
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
    else
        printf("Swapping is not possible\n");
}
