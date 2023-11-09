#include "ft_printf.h"

int ft_print_percentage(va_list *args)
{
    // The va_list is not used here, since '%' does not correspond to an argument.
    (void)args; // This is to explicitly state that args is unused to avoid compiler warnings.

    char c = '%';
    write(1, &c, 1);
    return (1);
}
