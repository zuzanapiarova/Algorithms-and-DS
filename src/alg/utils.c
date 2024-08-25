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
	if (!lst || pos <= 0)
		return (NULL);
	while (lst->next != NULL && pos > 1)
	{
		lst = lst->next;
		pos--;
	}
	return (lst);
}

