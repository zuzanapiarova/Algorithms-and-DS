#include "algorithms.h"

// NODE = data type that can stand on its own somewhere in memory
// we link them into a list by the 'next' pointer
// HEAD = first element of the list, keep it stored somewhere to not lose it as we iterate over the list
// set the next pointer of the last node to NULL so we know where it ends, just like setting '\0' at the end of strings
// to change the order or add a new node we just rearrange the pointers around it

//        (32 | o )   (8 | o )   (19 | o )   NULL
//   head__/    \____/     \____/      \____/
//                                              __________
//                                             /           \
//        (32 | o )   (8 | o )   (19 | o )   NULL     (10 | o )
//   head__/    \____/     \____/      \_____________/


// -- UTILS ---------------------------------------------------------

t_list	*ft_lstnew(void *content) // void pointer because we want to be able to store any type of data in the content of the node
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	if (content == 0)
	{
		result->content = 0;
		result->next = 0;
	}
	else
	{
		result->content = content;
		result->next = NULL;
	}
	return (result);
}

int	ft_lstsize(t_list *lst)
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

void	ft_lstadd_front(t_list **head, t_list *new)
{
	if (head != NULL && new != NULL)
	{
		new->next = *head;
		*head = new; // must update the head pointer to new head so the new head is kept and updated at memory
	}
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list	*temp;

	if (!head || !new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void print_list(t_list *head)
{
	t_list *current = head;

	while (current)
	{
		printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **head)
{
	t_list	*current;
	t_list	*next_node;

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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*result;
	t_list	*temp;

	result = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			del(temp->content);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}

// EXAMPLE PROGRAM

// int main(void)
// {
// 	int i = 0;
// 	t_list *lst = NULL; // initialize the list

// 	while (++i < 10)  // Use a loop to create new nodes
// 	{
// 		int *content = malloc(sizeof(int));  // Allocate space for the integer
// 		if (content == NULL)
// 		{
// 			return 1;  // Handle memory allocation failure
// 			ft_lstclear(&lst);
// 		}
// 		*content = i;  // Assign the value to the new integer
// 		ft_lstadd_front(&lst, ft_lstnew((void *)content));  // Add the new node to the front of the list
// 	}
// 	printf("List size: %d\n", ft_lstsize(lst));
// 	print_list(lst);
// 	ft_lstclear(&lst);  // Free all nodes and their content
// }
