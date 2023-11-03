/*
input: ft_lstadd_front(&lst, new)
function: add new to the front of lst
output: lst->new

1. Initialize empty list with `head = NULL`.
2. Create `node1` with content "Node 1". Add it to list. List: `node1 -> NULL`
3. Create `node2` with content "Node 2". Add it to list.
   - `new->next = node1`
   - `head = node2`
   List: `node2 -> node1 -> NULL`
4. Create `node3` with content "Node 3". Add it to list.
   - `new->next = node2`
   - `head = node3`
   List: `node3 -> node2 -> node1 -> NULL`
5. Print the list using `print_list()`, traverses from head to end.

Each `ft_lstadd_front` call updates the head and rearranges `next` pointers to maintain list integrity.
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

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst)
    {
        if (*lst)
            new->next = *lst;
        *lst = new;
    }
}

void print_list(t_list *lst)
{
    t_list *tmp = lst;
    while (tmp)
    {
        printf("Node content: %s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
}

int main()
{
    t_list *head = NULL; // Initialize empty list
    char *data1 = "Node 1"; // Create data for node1
    char *data2 = "Node 2"; // Create data for node2
    char *data3 = "Node 3"; // Create data for node3

    t_list *node1 = ft_lstnew(data1); // Create node1 with data1
    t_list *node2 = ft_lstnew(data2); // Create node2 with data2
    t_list *node3 = ft_lstnew(data3); // Create node3 with data3

    ft_lstadd_front(&head, node1); // Add node1 at the beginning
    ft_lstadd_front(&head, node2); // Add node2 at the beginning
    ft_lstadd_front(&head, node3); // Add node3 at the beginning

    print_list(head); // Should print Node 3, Node 2, Node 1

    return 0;
}

