#include <stdlib.h>
#include <stdio.h>

/* Define Node Structure: Define the structure of a node with data and a pointer to the next node. */

typedef struct s_node
{
    int data;
    struct s_node *next;
} Node;

/* Create New Node: Function to create a new node. */

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    printf("Created new node at %p with data %d\n", newNode, data);
    return newNode;
}


/* Add Node: Function to add a node at the end. */

void appendNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("List is empty. Setting new node as head at %p\n", *head);
        return;
    }
    printf("Current head is at %p\n", *head);
    Node *temp = *head;
    while (temp->next != NULL) {
        printf("Traversing node at %p. Next node is at %p\n", temp, temp->next);
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Appended new node at %p to the last node at %p\n", newNode, temp);
}

/* Traverse List: Function to print the list. */

void printList(Node *head) {
    Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d (%p) -> ", temp->data, temp);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Free List: Function to free allocated memory. */

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        printf("Freeing node at %p\n", temp);
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    appendNode(&head, 1);
    printf ("------------------\n");
    appendNode(&head, 2);
    printf ("------------------\n");
    appendNode(&head, 3);
    printf ("------------------\n");
    printList(head);
    printf ("------------------\n");
    freeList(head);
    return 0;
}
