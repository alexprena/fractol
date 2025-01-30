/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprenafe <aprenafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:33:08 by aprenafe          #+#    #+#             */
/*   Updated: 2024/09/21 20:43:17 by aprenafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_map_range	init_range(double min, double max)
{
	t_map_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

t_complex	init_complex(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_map_range	screen_x;
	t_map_range	screen_y;
	t_map_range	fract_x;
	t_map_range	fract_y;

	screen_x = init_range(0, WIDTH);
	screen_y = init_range(0, HEIGHT);
	fract_x = init_range(-2, 2);
	fract_y = init_range(2, -2);
	z.x = (map(x, fract_x, screen_x) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, fract_y, screen_y) * fractal->zoom) + fractal->shift_y;
	return (z);
}
