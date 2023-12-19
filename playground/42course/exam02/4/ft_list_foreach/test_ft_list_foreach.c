#include "ft_list.h"

// Test function that will be applied to each list element
void    my_test_function(void *data) {
    // Example: print the data assuming it's a string
    printf("%s\n", (char *)data);
}

// Function to create a new list element
t_list  *lst_new(void *data) {
    t_list *new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

int main() {
    // Create a test list
    t_list *list = lst_new("First");
    list->next = lst_new("Second");
    list->next->next = lst_new("Third");

    // Apply function to each element
    ft_list_foreach(list, &my_test_function);

    // Free the list (not shown here)
    // ...

    return 0;
}
