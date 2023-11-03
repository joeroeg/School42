/*
input: ft_lstdelone(&lst, del)
function: delete one element of lst using del and free
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

	// Content of Node2 before delete
	printf("Content of Node2: %d\n", *(int *)(Node2->content));

	// Delete Node
	ft_lstdelone(Node2, free);
	printf("Content of Node2: %d\n", *(int *)(Node2->content));

	// Free Memory
	free(Node1);
	return 0;
}

/*
If you are using local variables (value and value2) and storing their addresses in the nodes.
	t_list *Node2 = malloc(sizeof(t_list));
	int value2 = 10;
This is not suitable for deletion because the local variables are on the stack, not dynamically allocated.
*/
