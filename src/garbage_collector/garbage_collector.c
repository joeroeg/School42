#include "cub3d.h"

/**
 * @brief garbage_collector serves as an access point to the system
 * @return Return the address of the head
 * @param head Static variable to keep track of the head of the linked list
*/
t_mblock	*garbage_collector(void)
{
	static t_mblock	head = {NULL, NULL};

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

	memory_block = malloc(sizeof(t_mblock) * 1);
	if (!memory_block)
		error_message(MALLOC_ERROR, EXIT_FAILURE);
	memory_block->next = garbage_collector()->next;
	garbage_collector()->next = memory_block;
	memory_block->address = malloc(size);
	if (!memory_block->address)
		error_message(MALLOC_ERROR, EXIT_FAILURE);
	return (memory_block->address);
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

/**
 * @brief frees all dynamically allocated memory
 * @details It iterates through the memory blocks and frees them
 * It also closes the file descriptor and clears the mlx instance.
 * @return void
*/
void	gc_free_all(void)
{
	// free all memory blocks
	// close the file descriptor
	// clear the mlx instance
}
