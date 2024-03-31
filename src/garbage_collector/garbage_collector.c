#include "cub3d.h"

/**
 * @brief garbage_collector serves as an access point to the system
 * @return Return the address of the head
 * @param head Static variable to keep track of the head of the linked list
*/
t_mblock	*garbage_collector(void)
{
	static t_mblock	head = {NULL, -1, NULL};

	return (&head);
}

/**
 * @brief allocates memory and keeps track of it in a linked list
 * @param size is the size of the memory block to be allocated
 * @param memory_block is a pointer to a memory block structure
 * @return the address of the user data
 * @details After allocating, it inserts the new t_mblock into the linked list.
 * it keeps track of all allocated memory, making it easier to free later.
*/
void	*gc_malloc(size_t size)
{
	t_mblock	*memory_block;

	memory_block = malloc(sizeof(t_mblock));
	if (!memory_block)
		exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
	memory_block->fd = -1;
	memory_block->next = garbage_collector()->next;
	garbage_collector()->next = memory_block;
	memory_block->address = malloc(size);
	if (!memory_block->address)
	{
		free(memory_block);
		exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
	}
	return (memory_block->address);
}


/**
 * @brief gc_calloc allocates memory and keeps track of it in a linked list
 * @param count is the number of elements to be allocated
 * @param size is the size of each element
 * @return the address of the user data
*/
void	*gc_calloc(size_t count, size_t size)
{
	void	*address;

	address = gc_malloc(count * size);
	if (!address)
		exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
	ft_memset(address, 0, count * size);
	return (address);
}

/**
 * @brief frees all dynamically allocated memory
 * @details It iterates through memory blocks and frees them
 * It also closes the file descriptor and clears the mlx instance.
*/
void	gc_free(void *address)
{
	t_mblock	*gc_ptr;
	t_mblock	*ptr_copy;

	gc_ptr = garbage_collector()->next;
	ptr_copy = garbage_collector();
	while (gc_ptr)
	{
		if (gc_ptr->address == address)
		{
			ptr_copy->next = gc_ptr->next;
			if (gc_ptr->address)
				free(gc_ptr->address);
			free(gc_ptr);
			return ;
		}
		ptr_copy = gc_ptr;
		gc_ptr = gc_ptr->next;
	}
}

int	gc_open(const char *pathname, int flags, mode_t mode)
{
	t_mblock	*memory_block;
	int			fd;

	memory_block = malloc(sizeof(t_mblock));
	if (!memory_block)
		exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
	fd = open(pathname, flags, mode);
	if (fd == -1)
	{
		free(memory_block);
		return (-1);
	}
	memory_block->fd = fd;
	memory_block->address = NULL;
	memory_block->next = garbage_collector()->next;
	garbage_collector()->next = memory_block;
	return (fd);
}


void	gc_free_all(void)
{
	t_mblock	*current;
	t_mblock	*next;

	current = garbage_collector()->next;
	while (current != NULL)
	{
		next = current->next;
		if (current->fd != -1)
			close(current->fd);
		if (current->address)
			free(current->address);
		free(current);
		current = next;
	}
	garbage_collector()->next = NULL;
}

