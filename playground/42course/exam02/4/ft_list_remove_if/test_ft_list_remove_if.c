// Include your ft_list.h here
#include "ft_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Your ft_list_remove_if function
// ... ft_list_remove_if implementation ...

// Comparison function
int cmp(void *data1, void *data2) {
    return strcmp((char *)data1, (char *)data2);
}

// Helper function to create a new list node
t_list *create_elem(void *data) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print the list (for testing)
void print_list(t_list *list) {
    while (list) {
        printf("%s ", (char *)list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    // Creating a test list
    t_list *list = create_elem("one");
    list->next = create_elem("two");
    list->next->next = create_elem("three");
    list->next->next->next = create_elem("four");
    list->next->next->next->next = create_elem("five");

    printf("Original list: ");
    print_list(list);

    // Remove 'two' from the list
    ft_list_remove_if(&list, "five", &cmp);

    printf("Modified list: ");
    print_list(list);

    // Free the list (not shown here)

    return 0;
}
