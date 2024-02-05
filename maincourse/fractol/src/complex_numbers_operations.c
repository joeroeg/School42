/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers_operations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:16:12 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 20:17:39 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

t_complex	add(t_complex n1, t_complex n2)
{
	t_complex	temp;

	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	return (temp);
}

t_complex	subtract(t_complex n1, t_complex n2)
{
	t_complex	temp;

	temp.real = n1.real - n2.real;
	temp.imag = n1.imag - n2.imag;
	return (temp);
}

t_complex	multiply(t_complex n1, t_complex n2)
{
	t_complex	temp;

	temp.real = n1.real * n2.real - n1.imag * n2.imag;
	temp.imag = n1.real * n2.imag + n1.imag * n2.real;
	return (temp);
}

t_complex	divide(t_complex n1, t_complex n2)
{
	t_complex	temp;

	temp.real = (n1.real * n2.real + n1.imag * n2.imag) / \
		(n2.real * n2.real + n2.imag * n2.imag);
	temp.imag = (n2.real * n1.imag - n1.real * n2.imag) / \
		(n2.real * n2.real + n2.imag * n2.imag);
	return (temp);
}

double	t_complex_abs(t_complex z)
{
	return (sqrt(z.real * z.real + z.imag * z.imag));
}
