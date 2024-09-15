/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:33:44 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/24 15:59:45 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_aux(t_data *img, t_fractal f)
{
	int		i;
	float	zxt;

	i = 1;
	while (i < MAX_ITERATIONS)
	{
		zxt = f.zx;
		f.zx = (f.zx * f.zx) - (f.zy * f.zy) + f.cx;
		f.zy = 2 * zxt * f.zy + f.cy;
		if (sqrt((f.zx * f.zx) + (f.zy * f.zy)) > 2)
		{
			my_mlx_pixel_put(img, f.ox, f.oy, f.color * i);
			break ;
		}
		i ++;
	}
	if (i == MAX_ITERATIONS)
		my_mlx_pixel_put(img, f.ox, f.oy, BLACK);
}

void	mandelbrot(t_data *img, t_fractal f)
{
	float	aux_x;
	float	aux_y;

	aux_x = (f.xmax - f.xmin) / WIN_WIDTH;
	aux_y = (f.ymax - f.ymin) / WIN_WIDTH;
	while (f.ox < WIN_WIDTH)
	{
		f.cx = f.xmin + f.ox * aux_x;
		while (f.oy < WIN_WIDTH)
		{
			f.cy = f.ymin + f.oy * aux_y;
			mandelbrot_aux(img, f);
			f.oy += 1;
			f.zx = 0;
			f.zy = 0;
		}
		f.oy = 0;
		f.ox += 1;
	}
}
