#include "algorithms.h"

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
// @param lst pointer to the head of singly linked list
// @param el pointer to the value being searched for
// @returns position(starting with 1) of the element searched for or -1 in case it is not found or if the list is not ordered
s_list *binary_search(s_list *lst, void *el)
{
	s_list *mid;
	int size;

	if (!el || !lst || !check_ordered(lst) || *(int *)el > *(int *)ft_lstlast(lst)->content)
		return NULL;
	print_list(lst);
	size = ft_lstsize(lst);
	printf("size: %d\n", size);
	// if size is even, we choose the middle element to be the one closer to left eg.  size = 6, middle is 3
	if (size % 2 == 0)
		size = size / 2;
	else
	{
	// if list size is odd, the middle is going to be exactly the middle element, eg. size = 7, middle = 4 (3 numbers to top, 3 to zero)
		size -= 1;
		size =  size / 2;
		size = size + 1;
	}
	printf("new size: %d\n", size);

	mid = get_nth_element(lst, size);
	printf("value of mid: %d\n", *(int *)mid->content);

	if (*(int *)mid->content < *(int *)el && *(int *)mid->next->content > *(int *)el)
	{
		printf("Value not found. Reached element bigger than value searched for.\n");
		return NULL;
	}
	else if (*(int *)mid->content == *(int *)el)
	{
		printf("Found at mid: %d.\n", *(int *)mid->content);
		return mid;
	}
	else if (*(int *)mid->content >= *(int *)el)
	{
		printf("El is smaller than mid %d\n", *(int *)mid->content);
		ft_lstclear(&mid->next);
		mid = binary_search(lst, el);
	}
	else if (*(int *)mid->content <= *(int *)el)
	{
		printf("El is bigger than mid %d\n", *(int *)mid->content);
		// if there is list of size 2 left, it always sets the mid to the smaller element and is thus looped infinitely, following code handles this
		if (mid->next->next == NULL)
		{
			if (*(int *)mid->next->content == *(int *)el)
				mid = mid->next;
		}
		*lst = *mid;
		// TODO: free list items before the mid element that is the new beginning of the list
		mid = binary_search(lst, el);
	}
	return mid;
}

// EXAMPLE USE:
// int main(void)
// {
// 	int i = 0;
// 	int *content;
// 	int searched_value;
// 	s_list *lst = NULL;  // Initialize the list

// 	// creating new list
// 	while (i < 32)  // Use a loop to create new nodes
// 	{
// 		content = malloc(sizeof(int));  // Allocate space for the integer
// 		if (content == NULL)
// 		{
// 			ft_lstclear(&lst);
// 			return 1;  // Handle memory allocation failure
// 		}
// 		*content = i;  // Assign the value to the new integer
// 		ft_lstadd_back(&lst, ft_lstnew((void *)content));  // Add the new node to the front of the list
// 		i += 3;
// 	}
// 	// print list
// 	printf("List at start: ");
// 	print_list(lst);
// 	// element we search for
// 	searched_value =28;
// 	content = &searched_value;
// 	binary_search(lst, content);
// 	ft_lstclear(&lst);  // Free all nodes and their content
// }
