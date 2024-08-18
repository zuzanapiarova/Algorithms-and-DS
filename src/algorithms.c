#include "algorithms.h"

int main(void)
{
	int i = 0;
	t_list *lst = NULL;  // Initialize the list

	while (++i < 10)  // Use a loop to create new nodes
	{
		int *content = malloc(sizeof(int));  // Allocate space for the integer
		if (content == NULL)
		{
			return 1;  // Handle memory allocation failure
			ft_lstclear(&lst);
		}
		*content = i;  // Assign the value to the new integer
		ft_lstadd_front(&lst, ft_lstnew((void *)content));  // Add the new node to the front of the list
	}
	printf("List size: %d\n", ft_lstsize(lst));
	print_list(lst);
	ft_lstclear(&lst);  // Free all nodes and their content
}
