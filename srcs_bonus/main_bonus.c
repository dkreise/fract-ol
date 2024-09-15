/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:23:54 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/24 16:56:23 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_fractal f)
{
	if (f.set == MANDELBROT)
		mandelbrot(f.img, f);
	else if (f.set == JULIA)
		julia(f.img, f);
	else if (f.set == BURN_SHIP)
		burn_ship(f.img, f);
}

int	render(t_fractal *f)
{
	mlx_clear_window(f->img->mlx, f->img->win);
	key_hook_move(f);
	draw_fractal(*f);
	mlx_put_image_to_window(f->img->mlx, f->img->win, f->img->img, 0, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_fractal	f;
	t_movements	mov;

	f = create_fractal();
	mov = set_movements();
	if (argc <= 1)
		param_error();
	else
		set_name(&f, argv[1]);
	check_params(&f, argc, argv);
	img = init_img(argv);
	init_fractal(&f, img, mov);
	mlx_hook(img.win, 2, (1L << 0), &key_hook, &f);
	mlx_hook(img.win, 3, (1L << 0), &key_hook_release, &f);
	mlx_hook(img.win, 17, 0, &ft_close, &f);
	mlx_mouse_hook(img.win, mouse_hook, &f);
	mlx_loop_hook(img.mlx, render, &f);
	mlx_loop(img.mlx);
	return (0);
}
