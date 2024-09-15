/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:05:38 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/24 17:05:55 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MANDELBROT 1
# define JULIA 2
# define BURN_SHIP 3
# define ERROR1 "AVAILABLE PARAMETERS:\n\"Mandelbrot\"\n"
# define ERROR2 "\"Julia\" Re(c) Im(c) \tExample: \"Julia\" -0.4 0.6\n"
# define ERROR3 "\"Burning Ship\"\n"
# define WIN_WIDTH 1000
# define MAX_ITERATIONS 50
# define BLACK 0x00000000
# define COLOR1 0x00F8F4F5
# define COLOR2 0x00141335
# define COLOR3 0x00C005C0
# define COLOR4 0x00021F19
# define COLOR5 0x00F0D8C0
# define COLOR6 0x00F0F0D0
# define C 8
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define ZOOM 1.1
# define MOVE 0.05
# define ZOOM_OUT 4
# define ZOOM_IN 5

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
	unsigned int	color[6];
}				t_data;

typedef struct s_movements
{
	int	arrow_up;
	int	arrow_down;
	int	arrow_left;
	int	arrow_right;
	int	color_flag;
}				t_movements;

typedef struct s_fractal
{
	float			zx;
	float			zy;
	float			cx;
	float			cy;
	float			xmin;
	float			xmax;
	float			ymin;
	float			ymax;
	int				ox;
	int				oy;
	int				set;
	unsigned int	color;
	t_data			*img;
	t_movements		*mov;
}				t_fractal;

t_fractal	create_fractal(void);
void		init_fractal(t_fractal *f, t_data img, t_movements mov);
t_data		init_img(char **argv);
void		draw_fractal(t_fractal f);
void		mandelbrot(t_data *img, t_fractal f);
void		julia(t_data *img, t_fractal f);
void		burn_ship(t_data *img, t_fractal f);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
float		ft_atof(char *s);
void		param_error(void);
void		set_name(t_fractal *f, char *s);
void		check_params(t_fractal *f, int argc, char **argv);
int			ft_close(t_fractal *f);
int			mouse_hook(int button, int x, int y, t_fractal *f);
t_movements	set_movements(void);
int			key_hook(int key, t_fractal *f);
void		key_hook_move(t_fractal *f);
int			key_hook_release(int key, t_fractal *f);
#endif
