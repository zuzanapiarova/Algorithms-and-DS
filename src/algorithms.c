#include "algorithms.h"

int main(void)
{
	int *c1, *c2, *c3, *c4, *c5, *c6;
	s_list *lst = NULL;  // Initialize the list

	// creating new list
	c1 = malloc(sizeof(int));
	if (!c1)
	{
		ft_lstclear(&lst);
		return 1;
	}
	*c1 = 5;
	ft_lstadd_back(&lst, ft_lstnew((void *)c1));

	c2 = malloc(sizeof(int));
	if (!c2)
	{
		ft_lstclear(&lst);
		return 1;
	}
	*c2 = 8;
	ft_lstadd_back(&lst, ft_lstnew((void *)c2));

	c3 = malloc(sizeof(int));  // Allocate space for the integer
	if (!c3)
	{
		ft_lstclear(&lst);
		return 1;
	}
	*c3 = -52;
	ft_lstadd_back(&lst, ft_lstnew((void *)c3));

	c4 = malloc(sizeof(int));  // Allocate space for the integer
	if (!c4)
	{
		ft_lstclear(&lst);
		return 1;
	}
	*c4 = -12;
	ft_lstadd_back(&lst, ft_lstnew((void *)c4));

	c5 = malloc(sizeof(int));  // Allocate space for the integer
	if (!c5)
	{
		ft_lstclear(&lst);
		return 1;
	}
	*c5 = 25;
	ft_lstadd_back(&lst, ft_lstnew((void *)c5));

	c6 = malloc(sizeof(int));  // Allocate space for the integer
	if (!c6)
	{
		ft_lstclear(&lst);
		return 1;
	}
	*c6 = 1;
	ft_lstadd_back(&lst, ft_lstnew((void *)c6));

	// print list
	printf("List at start: ");
	print_list(lst);
	// perform sorting
	bubble_sort(&lst);
	printf("List at end: ");
	print_list(lst);
	ft_lstclear(&lst);  // Free all nodes and their content
}
