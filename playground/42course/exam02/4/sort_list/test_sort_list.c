#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Your sort_list function
// ... sort_list implementation ...

// Comparison function
int ascending(int a, int b)
{
    return (a <= b);
}

// Function to create a new list element
t_list *create_elem(int data) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the list (for testing)
void print_list(t_list *list) {
    while (list) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    // Create a test list
    t_list *list = create_elem(5);
    list->next = create_elem(3);
    list->next->next = create_elem(1);
    list->next->next->next = create_elem(4);
    list->next->next->next->next = create_elem(2);

    printf("Original list: ");
    print_list(list);

    // Sort the list
    list = sort_list(list, &ascending);

    printf("Sorted list: ");
    print_list(list);

    // Free the list (not shown here)
    // ...

    return 0;
}
