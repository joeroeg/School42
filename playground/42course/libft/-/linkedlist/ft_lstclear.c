/*
input: ft_lstclear(&lst, del)
function: delete all elements of lst using del and free
output: NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}


int main()
{
	// First Node
	t_list *head = NULL;
	t_list *Node1 = malloc(sizeof(t_list));
	int *value = malloc(sizeof(int));
	*value = 5;
	Node1->content = value;
	Node1->next = NULL;
	head = Node1;

	// Second Node
	t_list *Node2 = malloc(sizeof(t_list));
	int *value2 = malloc(sizeof(int));
	*value2 = 10;
	Node2->content = value2;
	Node2->next = NULL;
	Node1->next = Node2;

	// Content of Node1 and Node2 before clear
	printf("Content of Node1: %d\n", *(int *)(Node1->content));
	printf("Content of Node2: %d\n", *(int *)(Node2->content));

	// Clear Nodes
	ft_lstclear(&head, free);

	// Accessing Node1 or Node2 here would be undefined behavior
	printf("Content of Node1: %d\n", *(int *)(Node1->content));
	printf("Content of Node2: %d\n", *(int *)(Node2->content));

	return 0;
}
