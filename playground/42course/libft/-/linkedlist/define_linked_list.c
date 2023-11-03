#include <stdio.h> // this is the library to use printf
#include <stdlib.h> // this is the library to use malloc


struct s_list // this is the structure of the node. s_list is the name of the structure
{
  int data; // this is the data of the node
  struct s_list *next; // this is the next of the node
}; // this is the end of the structure. Do not forget the semicolon


int main()
{
	/* this is an example how to add node if you did not defined alias name with typedef*/

	// First node
	struct s_list *head = NULL; // this is the head of the linked list
	struct s_list *Node1 = malloc(sizeof(struct s_list)); // this is the first node
	Node1 -> data = 4; // this is the data of the first node
	Node1 -> next = NULL; // this is the next of the first node
	head = Node1; // this is the head of the linked list
	printf ("Node1 data: %d\n", Node1 -> data); // this is the data of the first node

	// Second node
	 struct s_list* Node2 = malloc(sizeof(struct s_list));
  	Node2->data = 2;
  	Node2->next = NULL;
  	Node1->next = Node2;
	printf ("Node2 data: %d\n", Node2 -> data); // this is the data of the second node

	struct s_list* temp = head; // this is the temp node to traverse the linked list from the head to the end
	int counter = 1; // this is the counter to count the number of nodes
  	while (temp != NULL) { // this is the loop to traverse the linked list from the head to the end
    printf("Node[%d] %d \n", counter, temp->data); // this is the data of the node
    temp = temp->next; // this is the next of the node
	counter++; // this is the counter to count the number of nodes
  }
	/* this is the end of adding 1 node */

	// Free Memory
	free(Node1);
	free(Node2);
}
