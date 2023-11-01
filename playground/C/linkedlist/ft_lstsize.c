/*
input: ft_lstsize(lst)
function: return the size of lst
output: size of lst
*/

#include <stdio.h>
#include <stdlib.h>

// typedef struct s_list
// {
//     void *content;
//     struct s_list *next;
// } t_list;

// int	ft_lstsize(t_list *lst)
// {
// 	size_t	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

struct s_list
{
  int data;
  struct s_list *next;
};


int main()
{
  struct s_list *head = NULL;
  struct s_list *Node1 = malloc(sizeof(struct s_list));
  Node1 -> data = 5;
  Node1 -> next = NULL;
  head = Node1;
  printf ("Node1 data: %d\n", Node1 -> data);
}
//   newNode->data = 5;
//   newNode->next = NULL;
//   head = newNode;

//   // Second Node
//   struct Node* secondNode = malloc(sizeof(struct Node));
//   secondNode->data = 10;
//   secondNode->next = NULL;
//   newNode->next = secondNode;

//   // Traverse List
//   struct Node* temp = head;
//   while (temp != NULL) {
//     printf("%d ", temp->data);
//     temp = temp->next;
//   }

//   // Free Memory
//   free(newNode);
//   free(secondNode);
