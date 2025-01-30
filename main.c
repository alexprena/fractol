/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:52:15 by aprenafe          #+#    #+#             */
/*   Updated: 2024/09/22 16:25:32 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_str_is_whitespace(const char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	julia_checker(char **argv, t_fractal *fractal)
{
	if (argv[2] == NULL || argv[3] == NULL || ft_strlen(argv[2]) == 0
		|| ft_strlen(argv[3]) == 0 || ft_str_is_whitespace(argv[2])
		|| ft_str_is_whitespace(argv[3]))
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (atodbl(argv[2]) >= -2 && atodbl(argv[2]) <= 2)
	{
		if (atodbl(argv[3]) >= -2 && atodbl(argv[3]) <= 2)
		{
			fractal->julia_x = atodbl(argv[2]);
			fractal->julia_y = atodbl(argv[3]);
		}
		else
		{
			ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 6))
		{
			julia_checker(argv, &fractal);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
