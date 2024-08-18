#include "algorithms.h"

// NULL <===> (32 | o ) <===> (8 | o ) <===> (19 | o ) <===> NULL
//             (head)                         (tail)

/* typedef struct d_list
{
	void			*content;
	struct d_list	*prev;
	struct d_list	*next;
}					d_list; */

d_list *dlst_create_new(void *content)
{
	d_list *node;

	node = (d_list *)malloc(sizeof(d_list));
	if (!node)
		return (NULL);
	if (content)
	{
		node->content = content;
		node->prev = NULL;
		node->next = NULL;
	}
	else
		return NULL;

	return (node);
}

void dlst_add_front(d_list **head, d_list *new)
{
	if (!new)
		return ;
	if (!*head)
	{
		new->prev = NULL;  // Set the previous pointer of the new head to NULL
		new->next = NULL;  // Set the next pointer of the new head to NULL
		*head = new;
		return ;
	}
	new->next = *head;
	new->prev = NULL;
	(*head)->prev = new;
	*head = new; // always set the new as the head at the end when inserting to front
}

void dlst_add_back(d_list **head, d_list *new)
{
	d_list	*temp;

	if (!new)
		return ;
	if (!*head)
	{
		new->prev = NULL;  // Set the previous pointer of the new head to NULL
		new->next = NULL;  // Set the next pointer of the new head to NULL
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
}

void print_dlist(d_list *head)
{
	d_list *current = head;

	while (current)
	{
		printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
}

void print_dlist_reverse(d_list *head)
{
	d_list *current = head;

	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		printf("%d\n", *(int *)(current->content));
		current = current->prev;
	}
}

void	ft_dlstclear(d_list **head)
{
	d_list	*current;
	d_list	*next_node;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		next_node = current->next;
		free(current->content); // we free the content first because we passed it in as pointer created by allocating memory, so we have to free it
		free(current); // only after content is freed we can free the node itself
		current = next_node;
	}
	*head = NULL;
}

int	ft_dlstsize(d_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// EXAMPLE  PROGRAM

// int main(void)
// {
// 	int i = 0;
// 	d_list *lst = NULL;  // Initialize the list

// 	while (++i < 10)  // Use a loop to create new nodes
// 	{
// 		int *content = malloc(sizeof(int));  // Allocate space for the integer
// 		if (content == NULL)
// 		{
// 			ft_dlstclear(&lst);
// 			return 1;  // Handle memory allocation failure
// 		}
// 		*content = i;  // Assign the value to the new integer
// 		dlst_add_back(&lst, dlst_create_new((void *)content));  // Add the new node to the front of the list
// 	}
// 	printf("List size: %d\n", ft_dlstsize(lst));
// 	print_dlist_reverse(lst);
// 	ft_dlstclear(&lst);  // Free all nodes and their content
// }
