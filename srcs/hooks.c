/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:37:29 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/24 16:13:23 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_close(t_fractal *f)
{
	mlx_destroy_window(f->img->mlx, f->img->win);
	exit(1);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	float	fx;
	float	fy;
	float	xlen;
	float	ylen;

	fx = (float)x / WIN_WIDTH;
	fy = (float)y / WIN_WIDTH;
	xlen = f->xmax - f->xmin;
	ylen = f->ymax - f->ymin;
	if (button == ZOOM_OUT)
	{
		f->xmin = f->xmin - (xlen * ZOOM - xlen) * fx;
		f->xmax = f->xmax + (xlen * ZOOM - xlen) * (1 - fx);
		f->ymin = f->ymin - (ylen * ZOOM - ylen) * fy;
		f->ymax = f->ymax + (ylen * ZOOM - ylen) * (1 - fy);
	}
	if (button == ZOOM_IN)
	{
		f->xmin = f->xmin - (xlen / ZOOM - xlen) * fx;
		f->xmax = f->xmax + (xlen / ZOOM - xlen) * (1 - fx);
		f->ymin = f->ymin - (ylen / ZOOM - ylen) * fy;
		f->ymax = f->ymax + (ylen / ZOOM - ylen) * (1 - fy);
	}
	return (0);
}

int	key_hook(int key, t_fractal *f)
{
	if (key == C)
	{
		f->mov->color_flag ++;
		f->color = f->img->color[f->mov->color_flag];
	}
	if (key == ESC)
		ft_close(f);
	if (key == ARROW_LEFT)
		f->mov->arrow_left = 1;
	if (key == ARROW_RIGHT)
		f->mov->arrow_right = 1;
	if (key == ARROW_DOWN)
		f->mov->arrow_down = 1;
	if (key == ARROW_UP)
		f->mov->arrow_up = 1;
	return (0);
}

void	key_hook_move(t_fractal *f)
{
	float	xlen;
	float	ylen;

	xlen = f->xmax - f->xmin;
	ylen = f->ymax - f->ymin;
	if (f->mov->arrow_left == 1)
	{
		f->xmin -= MOVE * xlen;
		f->xmax -= MOVE * xlen;
	}
	if (f->mov->arrow_right == 1)
	{
		f->xmin += MOVE * xlen;
		f->xmax += MOVE * xlen;
	}
	if (f->mov->arrow_up == 1)
	{
		f->ymin -= MOVE * ylen;
		f->ymax -= MOVE * ylen;
	}
	if (f->mov->arrow_down == 1)
	{
		f->ymin += MOVE * ylen;
		f->ymax += MOVE * ylen;
	}
}

int	key_hook_release(int key, t_fractal *f)
{
	if (key == C)
	{
		if (f->mov->color_flag == 5)
			f->mov->color_flag = -1;
	}
	if (key == ESC)
		ft_close(f);
	if (key == ARROW_LEFT)
		f->mov->arrow_left = 0;
	if (key == ARROW_RIGHT)
		f->mov->arrow_right = 0;
	if (key == ARROW_DOWN)
		f->mov->arrow_down = 0;
	if (key == ARROW_UP)
		f->mov->arrow_up = 0;
	return (0);
}
