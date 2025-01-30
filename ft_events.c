/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:06:24 by aprenafe          #+#    #+#             */
/*   Updated: 2024/09/21 21:30:27 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (!fractal)
	{
		fprintf(stderr, "Error: fractal es NULL\n");
		return (-1);
	}
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.2 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.2 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.2 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.2 * fractal->zoom);
	else if (keysym == XK_equal || keysym == XK_KP_Add)
		fractal->iterations += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
	{
		if (fractal->iterations > 10)
			fractal->iterations -= 10;
	}
	fractal_render (fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, void *fractal1)
{
	t_fractal	*fractal;

	(void)x;
	(void)y;
	fractal = (t_fractal *)fractal1;
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}
