/*
input: ft_lstlast(lst)
function: return the last element of lst
output: lst->last
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int main()
{
	// First Node
	t_list *head = NULL;
	t_list *Node1 = malloc(sizeof(t_list));
	int value = 5;
	Node1->content = &value;
	Node1->next = NULL;
	head = Node1;

	// Second Node
	t_list *Node2 = malloc(sizeof(t_list));
	int value2 = 10;
	Node2->content = &value2;
	Node2->next = NULL;
	Node1->next = Node2;

	// Get Last Node
	t_list *lastNode = ft_lstlast(head);
	printf("Content of last node: %d\n", *(int *)(lastNode->content));

	// Free Memory
	free(Node1);
	free(Node2);

    return 0;
}
