#include "algorithms.h"

int selection_sort(s_list **head)
{
	if (!head || !*head)
		return (0);
	if (!(*head)->next)
		return (1);
	return 1;
}
