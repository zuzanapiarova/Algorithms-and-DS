#include "algorithms.h"

// UTILS
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

// LINEAR SEARCH
// @param lst pointer to head of singly linked list
// @param el pointer to the value being searched for
// @returns position(starting with 1) of the element searched for or -1 in case it is not found
int linear_search(s_list *lst, void *el)
{
	int pos;
	s_list *temp;

	if (!el || !lst)
		return (-1);
	pos = 0;
	temp = lst;
	bool ordered = check_ordered(lst);
	printf("is ordered: %d\n", ordered);
	while (temp != NULL)
	{
		pos++;
		if (*(int *)temp->content == *(int *)el)
		{
			printf("Value %d found at position %d (%d)\n", *(int *)el, pos, *(int *)temp->content);
			return (pos);
		}
		if (ordered && *(int *)temp->content > *(int *)el)
		{
			printf("Not found. Reached higher value than %d in ordered list.\n", *(int *)el);
			return (-1);
		}
		temp = temp->next;
	}
	printf("Value %d not found.\n", *(int *)el);
	return (-1);
}

// EXAMPLE PROGRAM 1
// int main(void)
// {
// 	int i = 0;
// 	int *content;
// 	int searched_value;
// 	s_list *lst = NULL;  // Initialize the list

// 	// creating new list
// 	while (i < 20)  // Use a loop to create new nodes
// 	{
// 		content = malloc(sizeof(int));  // Allocate space for the integer
// 		if (content == NULL)
// 		{
// 			ft_lstclear(&lst);
// 			return 1;  // Handle memory allocation failure
// 		}
// 		*content = i;  // Assign the value to the new integer
// 		ft_lstadd_back(&lst, ft_lstnew((void *)content));  // Add the new node to the front of the list
// 		i += 2;
// 	}
// 	// print list
// 	print_list(lst);
// 	// element we search for
// 	searched_value = 2;
// 	content = &searched_value;
// 	linear_search(lst, content);
// 	ft_lstclear(&lst);  // Free all nodes and their content
// }

// BINARY SEARCH
