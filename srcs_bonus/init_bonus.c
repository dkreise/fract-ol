/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:47:41 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/24 16:54:55 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractol_bonus.h"

t_fractal	create_fractal(void)
{
	t_fractal	f;

	f.zx = 0.;
	f.zy = 0.;
	f.cx = 0.;
	f.cy = 0.;
	f.ox = 0;
	f.oy = 0;
	f.xmin = -2.;
	f.xmax = 2.;
	f.ymin = -2.;
	f.ymax = 2.;
	return (f);
}

void	init_fractal(t_fractal *f, t_data img, t_movements mov)
{
	f->img = &img;
	f->mov = &mov;
	f->color = img.color[0];
	if (f->set == BURN_SHIP)
	{
		f->xmin = -1.95;
		f->xmax = -1.65;
		f->ymin = -0.15;
		f->ymax = 0.15;
	}
}

t_data	init_img(char **argv)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_WIDTH, argv[1]);
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_len, &img.endian);
	img.color[0] = COLOR1;
	img.color[1] = COLOR2;
	img.color[2] = COLOR3;
	img.color[3] = COLOR4;
	img.color[4] = COLOR5;
	img.color[5] = COLOR6;
	return (img);
}

t_movements	set_movements(void)
{
	t_movements	mov;

	mov.arrow_left = 0;
	mov.arrow_right = 0;
	mov.arrow_up = 0;
	mov.arrow_down = 0;
	mov.color_flag = 0;
	return (mov);
}
