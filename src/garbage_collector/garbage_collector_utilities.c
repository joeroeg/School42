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
