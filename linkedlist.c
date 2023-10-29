#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

void print_content(void *content) {
    printf("%d\n", *(int *)content);
}

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

int main() {
    // Create a 3-node linked list
    t_list node1, node2, node3;
    int val1 = 1, val2 = 2, val3 = 3;

    node1.content = &val1;
    node1.next = &node2;

    node2.content = &val2;
    node2.next = &node3;

    node3.content = &val3;
    node3.next = NULL;

    // Apply ft_lstiter to print each node's content
    ft_lstiter(&node1, print_content);

    return 0;
}
