#include "algorithms.h"

int main(void)
{
	int i = 0;
	int *content;
	int searched_value;
	s_list *lst = NULL;  // Initialize the list

	// creating new list
	while (i < 20)  // Use a loop to create new nodes
	{
		content = malloc(sizeof(int));  // Allocate space for the integer
		if (content == NULL)
		{
			ft_lstclear(&lst);
			return 1;  // Handle memory allocation failure
		}
		*content = i;  // Assign the value to the new integer
		ft_lstadd_back(&lst, ft_lstnew((void *)content));  // Add the new node to the front of the list
		i += 2;
	}
	// print list
	print_list(lst);
	// element we search for
	searched_value = 2;
	content = &searched_value;
	linear_search(lst, content);
	ft_lstclear(&lst);  // Free all nodes and their content
}
