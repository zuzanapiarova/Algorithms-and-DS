#include "algorithms.h"

int main(void)
{
	int i = 0;
	d_list *lst = NULL;  // Initialize the list

	while (++i < 10)  // Use a loop to create new nodes
	{
		int *content = malloc(sizeof(int));  // Allocate space for the integer
		if (content == NULL)
		{
			return 1;  // Handle memory allocation failure
			ft_dlstclear(&lst);
		}
		*content = i;  // Assign the value to the new integer
		dlst_add_back(&lst, dlst_create_new((void *)content));  // Add the new node to the front of the list
	}
	printf("List size: %d\n", ft_dlstsize(lst));
	print_dlist_reverse(lst);
	ft_dlstclear(&lst);  // Free all nodes and their content
}
