/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkreise <dkreise@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:34:27 by dkreise           #+#    #+#             */
/*   Updated: 2023/12/24 15:27:24 by dkreise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 ++;
		s2 ++;
	}
	return (*s1 - *s2);
}

float	ft_atof(char *s)
{
	int		i;
	float	n;
	int		sign;
	float	div;

	i = 0;
	n = 0.;
	sign = 1;
	div = 0.1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
		n = n * 10 + (s[i++] - '0');
	if (s[i] == '.' || s[i] == ',')
		i ++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n += (s[i++] - '0') * div;
		div *= 0.1;
	}
	return (n * sign);
}

void	param_error(void)
{
	write(1, ERROR1, sizeof(ERROR1));
	write(1, ERROR2, sizeof(ERROR2));
	write(1, ERROR3, sizeof(ERROR3));
	exit(1);
}

void	check_params(t_fractal *f, int argc, char **argv)
{
	if (f->set == JULIA && argc >= 4)
	{
		f->cx = ft_atof(argv[2]);
		f->cy = ft_atof(argv[3]);
	}
}

void	set_name(t_fractal *f, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
		i ++;
	}
	if (ft_strcmp(s, "mandelbrot") == 0)
		f->set = MANDELBROT;
	else if (ft_strcmp(s, "julia") == 0)
	{
		f->set = JULIA;
		f->cx = -0.835;
		f->cy = -0.232;
	}
	else if (ft_strcmp(s, "burning") == 0)
		f->set = BURN_SHIP;
	else if (ft_strcmp(s, "burning ship") == 0)
		f->set = BURN_SHIP;
	else
		param_error();
}
