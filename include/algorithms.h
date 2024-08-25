#ifndef ALGORITHMS_AND_DATA_STRUCTURES
# define ALGORITHMS_AND_DATA_STRUCTURES

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// BINARY TREE -----------------------------------------------------------------

typedef struct	treenode
{
	int value;
	struct treenode *left; // left child
	struct treenode *right; // right child
}				treenode;

treenode *create_node(int value);
treenode *fill_tree(void);
void free_tree(treenode *root);

void preorder_traversal(treenode *root);
void inorder_traversal(treenode *root);
void postorder_traversal(treenode *root);
void breadth_first_traversal(treenode *root);

// SINGLY LINKED LIST ---------------------------------------------------------

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					s_list;

void	ft_lstadd_back(s_list **lst, s_list *new);
void	ft_lstadd_front(s_list **lst, s_list *new);
s_list	*ft_lstnew(void *content);
int		ft_lstsize(s_list *lst);
void	ft_lstclear(s_list **lst);
void	ft_lstdelone(s_list *lst, void (*del)(void*));
void	ft_lstiter(s_list *lst, void (*f)(void *));
s_list	*ft_lstlast(s_list *lst);
s_list	*ft_lstmap(s_list *lst, void *(*f)(void*), void (*del)(void*));
void	print_list(s_list *head);

// DOUBLY LINKED LIST (CHAIN) --------------------------------------------------

typedef struct d_list
{
	void			*content;
	struct d_list	*prev;
	struct d_list	*next;
}					d_list;

d_list *dlst_create_new(void *content);
void dlst_add_front(d_list **head, d_list *new);
void dlst_add_back(d_list **head, d_list *new);
void print_dlist(d_list *head);
void print_dlist_reverse(d_list *head);
int	ft_dlstsize(d_list *lst);
void	ft_dlstclear(d_list **head);

// LIST ALGORITHMS ---------------------------------------------------------------

int linear_search(s_list *lst, void *el);
s_list *binary_search(s_list *lst, void *el);
int insertion_sort(s_list **head);

// UTILS -------------------------------------------------------------------------
bool check_ordered(s_list *lst);
s_list	*get_nth_element(s_list *lst, int pos);

#endif
