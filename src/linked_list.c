#include "algorithms.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*el;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		el = *lst;
		while (el->next != NULL)
			el = el->next;
		el->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_node	*ft_lstnew(int value)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->value = value;
	result->next = NULL;
	return (result);
}

void print_stack(t_stack *stack)
{
	printf("stack %s, size: %d\n", stack->name, stack->size);
	t_node *current = stack->head;
	printf("-------------\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("-------------\n");
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_el;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current_el = *lst;
	while (current_el)
	{
		temp = current_el->next;
		del(current_el->content);
		free(current_el);
		current_el = temp;
	}
	*lst = NULL;
}


void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
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

t_list	*ft_lstnew(void *content)
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

