/*
input: ft_lstnew("Hello")
function: create a new node with content "Hello"
output: "Hello"
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int main()
{
	// Single Data Node
	int a = 42;
	t_list *node1 = ft_lstnew(&a);
	printf("Single Data Node content: %d\n", *((int *)node1->content));

	// Multiple Data Nodes
	int b = 43;
	char c[] = "Hello ";
	char d[] = "World!";
	t_list *node2 = ft_lstnew(&b); // we set node2->content to &b (address of b) | node2->next = NULL
	t_list *node3 = ft_lstnew(&c); // we set node3->content to &c (address of c) | node3->next = NULL
	t_list *node4 = ft_lstnew(&d); // we set node4->content to &d (address of d) | node4->next = NULL
	node2->next = node3; // we set node2->next to node3 because node2->next is NULL
	node3->next = node4; // we set node3->next to node4 because node3->next is NULL
	printf("Multiple Data Nodes content: %d\n", *((int *)node2->content)); // we print the content of node2 which is the address of b
	printf("Multiple Data Nodes content: %s\n", ((char *)node2->next->content)); // or shorthand node3->content we print the content of node2->next which is the address of c
	printf("Multiple Data Nodes content: %s\n", ((char *)node2->next->next->content)); // or shorthand node4-> content we print the content of node2->next->next which is the address of d

	// Array of Data Nodes are used to store data of the same type
	int arr[] = {1, 2, 3};
	t_list *node5 = ft_lstnew(arr);
	for (int i = 0; i < 3; i++)
		printf("Array elements: %d\n", ((int *)node5->content)[i]);

	// Struct Node is used to store data of different types
	typedef struct {
		int id;
		char name[10];
	} Person;

	Person p = {1, "Alice"};
	t_list *node6= ft_lstnew(&p);
	printf("Person id: %d \nPerson name: %s\n", ((Person *)node6->content)->id, ((Person *)node6->content)->name);

	// Nested Lists
	t_list *inner_node = ft_lstnew(&a);
	t_list *outer_node = ft_lstnew(inner_node);
	printf("Inner node content: %d\n", *((int *)((t_list *)outer_node->content)->content));


	// Dynamic Data Node (malloc)
	int *dynamic_data = malloc(sizeof(int));
	*dynamic_data = 99;
	t_list *node7 = ft_lstnew(dynamic_data);
	printf("Dynamic data: %d\n", *((int *)node7->content));

	/* Queue/Stack */

	// Stack push operation (LIFO) is the same as adding a new node to the beginning of the list
	t_list *top = NULL;
	int item = 5;
	t_list *new_node = ft_lstnew(&item);
	new_node->next = top;
	top = new_node;

	// Stack pop operation (LIFO) is the same as removing the first node from the list
	if (top) {
		int popped = *((int *)top->content);
		t_list *tmp = top;
		top = top->next;
		free(tmp);
		printf("Popped: %d\n", popped);
	}


	return (0);
}
