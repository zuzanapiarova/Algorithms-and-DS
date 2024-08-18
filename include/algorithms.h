#ifndef ALGORITHMS_AND_DATA_STRUCTURES
# define ALGORITHMS_AND_DATA_STRUCTURES

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"

// SINGLY LINKED LIST
typedef struct s_vars
{
	char		**arr;
	size_t		i;
	size_t		j;
	size_t		start_i;
}				t_vars;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_node
{
	int		value;
	struct s_node	*next;

}				t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
	char	*name;
}				t_stack;

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

void print_stack(t_stack *stack);

// DOUBLY LINKED LIST (CHAIN)

// BINARY TREE
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

#endif
