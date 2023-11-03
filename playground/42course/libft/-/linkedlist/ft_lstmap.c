/*
input: ft_lstmap(lst, f, del)
function: iterate through lst and apply f to each element
output: new list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	free_content(void *content)
{
    free(content);
}

t_list	*ft_lstnew(void *content)
{
    t_list *new_node = malloc(sizeof(t_list));
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst)
    {
        if (*lst)
            new->next = *lst;
        *lst = new;
    }
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp = *lst;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
			ft_lstclear(&first, del);
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

void	*double_content(void *content)
{
    int *result = malloc(sizeof(int));
    if (result)
        *result = 2 * *(int *)content;
    return result;
}

void	del_content(void *content)
{
    free(content);
}

int		main(void)
{
    t_list *list = NULL;
    int *value;

    for (int i = 1; i <= 5; i++) {
        value = malloc(sizeof(int));
        *value = i;
        ft_lstadd_back(&list, ft_lstnew(value));
    }

    t_list *new_list = ft_lstmap(list, double_content, del_content);

    for (t_list *tmp = new_list; tmp; tmp = tmp->next) {
        printf("%d ", *(int *)tmp->content);
    }
    printf("\n");

    ft_lstclear(&list, del_content);
    ft_lstclear(&new_list, del_content);

    return 0;
}
