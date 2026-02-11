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

void	init_window(t_all *all)
{
	all->mlx = mlx_init();
	if (!all->mlx)
		exit(1);
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "Fractol");
	if (!all->win)
		exit(1);
}

void	pixel_to_complex(int x, int y, t_all *all, t_pix *p)
{
	double	re_step;
	double	im_step;
	t_view	*v;

	v = &all->view;
	re_step = (v->max_re - v->min_re) / (WIDTH * all->zoom);
	im_step = (v->max_im - v->min_im) / (HEIGHT * all->zoom);
	p->cr = v->min_re + (x * re_step) + all->x_offset;
	p->ci = v->max_im - (y * im_step) + all->y_offset;
}

void	mouse_to_complex(int x, int y, t_all *all, t_pix *p)
{
	double	re_step;
	double	im_step;
	t_view	*v;

	v = &all->view;
	re_step = (v->max_re - v->min_re) / WIDTH;
	im_step = (v->max_im - v->min_im) / HEIGHT;
	p->cr = v->min_re + x * re_step;
	p->ci = v->max_im - y * im_step;
}

static void	clear_image(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&all->img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_all *all)
{
	t_pix	p;

	clear_image(all);
	if (all->type == LEAF)
	{
		draw_tree(all);
		return ;
	}
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			pixel_to_complex(p.x, p.y, all, &p);
			if (all->type == MANDELBROT)
			{
				p.iter = mandelbrot(p.cr, p.ci);
				p.color = get_color(p.iter);
			}
			else if (all->type == JULIA)
			{
				p.iter = julia(p.cr, p.ci, all);
				p.color = get_color(p.iter);
			}
			my_mlx_pixel_put(&all->img, p.x, p.y, p.color);
			p.x++;
		}
		p.y++;
	}
}
