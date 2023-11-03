/*
input: ft_lstsize(lst)
function: return the size of lst
output: size of lst
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

	// Count Nodes
	int nodeCount = ft_lstsize(head);
	printf("Total Nodes: %d\n", nodeCount);

  // Free Memory
  free(Node1);
  free(Node2);

}
