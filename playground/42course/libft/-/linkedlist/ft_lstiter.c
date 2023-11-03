/*
input: ft_lstiter(lst, f)
function: iterate through lst and apply f to each element
output: NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

void print_content(void *content)
{
	printf("%d\n", *(int *)content);
}

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
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

	// Use ft_lstiter to print each node's content
	ft_lstiter(head, print_content);

	// Free Memory
	free(value);
	free(value2);
	free(Node1);
	free(Node2);

	return 0;
}
