/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:05:44 by marvin            #+#    #+#             */
/*   Updated: 2025/11/20 21:05:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_view(t_view *v)
{
	v->min_re = -2.0;
	v->max_re = 1.0;
	v->min_im = -1.5;
	v->max_im = 1.5;
}

void pixel_to_complex(int x, int y, t_view *v, double *cr, double *ci, t_all *all)
{
    double re_step = (v->max_re - v->min_re) / WIDTH / all->zoom;
    double im_step = (v->max_im - v->min_im) / HEIGHT / all->zoom;

    *cr = v->min_re + (x * re_step) + all->x_offset;
    *ci = v->max_im - (y * im_step) + all->y_offset;
}


void	mouse_to_complex(int x, int y, t_view *v, double *cr, double *ci)
{
	double	re_step;
	double	im_step;

	re_step = (v->max_re - v->min_re) / WIDTH;
	im_step = (v->max_im - v->min_im) / HEIGHT;
	*cr = v->min_re + x * re_step;
	*ci = v->max_im - y * im_step;
}

void	draw_fractal(t_all *all)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		iter;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_complex(x, y, &all->view, &cr, &ci, all);
			if (all->type == 1)
				iter = mandelbrot(cr, ci);
			else
				iter = julia(cr, ci, all->julia_re, all->julia_im);
			color = get_color(iter);
			my_mlx_pixel_put(&all->img, x, y, color);
			x++;
		}
		y++;
	}
}