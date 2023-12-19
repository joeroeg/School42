#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	// initialize tmp with the head of the list (lst).
	// this is important for being able to iterate over the list multiple times.
	tmp = lst;
	// start of the Outer Loop:
	while(lst->next != NULL)
	{
		// comparison and Possible Swap:
		// here, the data in the current node (lst->data) and the next node (lst->next->data) are compared using the cmp function.
		// if cmp returns 0, it indicates that these two elements are not in the correct order according to the sorting criteria.
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			// these lines perform the swap of the data between the current node and the next node.
			// this is done by using the swap variable as a temporary storage.
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			// resetting to start of the list:
			lst = tmp;
			// if a swap has occurred, the lst pointer is reset to tmp, which is the head of the list.
			// this is because after a swap, the list needs to be checked again from the beginning to ensure it's sorted.
		}
		// advancing to the next element:
		else
			lst = lst->next;
		// if no swap was needed the function moves to the next node in the list.
	}
	lst = tmp;
	return (lst);
}

// Assuming the ascending function is defined elsewhere, for example:
int ascending(int a, int b)
{
    return (a <= b);
}

// Function to create a new node
t_list *new_node(int data)
{
    t_list *new_node = malloc(sizeof(t_list));
    if (new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

// Function to append a node to the list
		void append(t_list **list, int data)
		{
			t_list *newNode = new_node(data);
			t_list *last = *list;

			if (*list == NULL)
			{
				*list = newNode;
				return;
			}

			while (last->next != NULL)
				last = last->next;

			last->next = newNode;
		}

// Function to print the list
void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main(void)
{
	// Create a t_list strcuture
    t_list *test_list = NULL;

    // Append data to the list
    append(&test_list, 3);
    append(&test_list, 1);
    append(&test_list, 4);
    append(&test_list, 2);

    printf("Original List: ");
    print_list(test_list);

    // Sort the list
    test_list = sort_list(test_list, ascending);

    printf("Sorted List: ");
    print_list(test_list);

    // Free the list
    while (test_list != NULL)
    {
        t_list *temp = test_list;
        test_list = test_list->next;
        free(temp);
    }

    return 0;
}
