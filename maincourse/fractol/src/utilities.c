/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:23:08 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:59 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	print_help(int should_exit)
{
	printf("\033[0m\033[34mUsage: ./fractol [number]\n\n\033[0m");
	printf("\033[32mFunctionality:\n");
	printf("press  --> 'c' to change the color\n");
	printf("press  --> 'esc' to exit the program\n");
	printf("press  --> '↑' '↓' '←' '→'\n");
	printf("scroll --> to zoom in and out\n\n\033[0m");
	printf("\033[33mAvailable Sets\n\n");
	printf("   --> 1️⃣  Mandelbrot\n");
	printf("   --> 2️⃣  Julia\n");
	printf("	|-> For Julia, please provide 2 arguments:\n");
	printf("	|-> ./fractol 2 [A] [B]\n\n");
	printf("	|-> Few examples that you could try\n");
	printf("	|-> ./fractol 2 -0.9 0.234\n");
	printf("	|-> ./fractol 2 0.285 0.01\n");
	printf("	|-> ./fractol 2 -0.70176 -0.3842\n");
	printf("	|-> ./fractol 2 -0.835 -0.2321\n");
	printf("	|-> ./fractol 2 -0.7269 0.456\n\033[0m");
	printf("   --> 3️⃣  Burningship\n");
	printf("   --> 4️⃣  Newton\n");
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

void	cleanup(t_fractol *data)
{
	mlx_terminate(data->mlx);
	free(data);
}
