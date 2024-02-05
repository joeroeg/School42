/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:23:08 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 20:47:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	print_help(int should_exit)
{
	printf("Usage: ./fractol [fractal_set_nb]\n\n");
	printf("Available Sets\n\n");
	printf("   --> 1️⃣  Mandelbrot\n");
	printf("   --> 2️⃣  Julia\n");
	printf("   --> 3️⃣  Burningship\n");
	printf("   --> 4️⃣  Newton\n");
	printf("    |-> For Julia, please provide 2 arguments:\n");
	printf("    |-> ./fractol 2 [A] [B]\n\n");
	printf("    |-> Few examples that you could try\n");
	printf("    |-> ./fractol 2 -0.8 0.156\n");
	printf("    |-> ./fractol 2 0.285 0.01\n");
	printf("    |-> ./fractol 2 -0.70176 -0.3842\n");
	printf("    |-> ./fractol 2 -0.835 -0.2321\n");
	printf("    |-> ./fractol 2 -0.7269 0.456\n");
	if (should_exit == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

static int	check_sign(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	if (!str)
		return (0);
	i = 0;
	result = 0.0;
	decimal = 1.0;
	if (str[i])
	{
		sign = check_sign(str);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	return (sign * result / decimal);
}

void	cleanup(t_fractol *frctl)
{
	mlx_terminate(frctl->mlx);
	free(frctl);
}
