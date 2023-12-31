/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:01:07 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/31 17:25:12 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_snprintf_data
{
	const char	**format_ptr;
	va_list		*args;
	char		**buf_ptr;
	size_t		*size;
	int			*total_written;
}	t_snprintf_data;

/* Adds a non-format character to the buffer */
static void	add_char_to_buf(char **buf_ptr, size_t *size, \
	char c, int *total_written)
{
	if (*total_written < *size - 1)
		*(*buf_ptr)++ = c;
	(*total_written)++;
}

/* Handles the string format specifier */
static int	handle_str_spec(char **buf_ptr, size_t *size, const char *val_str)
{
	int		written;

	written = 0;
	while (*val_str)
	{
		if (written < *size - 1)
			*(*buf_ptr)++ = *val_str;
		written++;
		val_str++;
	}
	return (written);
}

/* Handles the integer format specifier */
static int	handle_int_spec(char **buf_ptr, size_t *size, int val_int)
{
	char	num_buf[20];
	char	*num_ptr;
	int		written;

	snprintf(num_buf, sizeof(num_buf), "%d", val_int);
	num_ptr = num_buf;
	written = 0;
	while (*num_ptr)
	{
		if (written < *size - 1)
			*(*buf_ptr)++ = *num_ptr;
		written++;
		num_ptr++;
	}
	return (written);
}

/* Processes format specifiers */
static void process_format_specifier(t_snprintf_data *data)
{
	(*(data->format_ptr))++;
	if (**(data->format_ptr) == 's')
		*(data->total_written) += handle_str_spec(data->buf_ptr, \
			data->size, va_arg(*(data->args), const char *));
	else if (**(data->format_ptr) == 'd')
		*(data->total_written) += handle_int_spec(data->buf_ptr, \
			data->size, va_arg(*(data->args), int));
}

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list			args;
	const char		*p;
	char			*buf_ptr;
	int				total_written;
	t_snprintf_data	data;

	va_start(args, format);
	p = format;
	buf_ptr = str;
	total_written = 0;
	data = (t_snprintf_data){&p, &args, &buf_ptr, &size, &total_written};
	while (*p != '\0')
	{
		if (*p != '%')
		{
			add_char_to_buf(&buf_ptr, &size, *p, &total_written);
			p++;
			continue ;
		}
		process_format_specifier(&data);
		p++;
	}
	va_end(args);
	if (size > 0)
		*buf_ptr = '\0';
	return (total_written);
}
