/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhamis <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:19:48 by marvin            #+#    #+#             */
/*   Updated: 2025/11/16 15:19:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
#include <stddef.h>


# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define MANDELBROT 1
# define JULIA      2
# define NEWTON     3
# define KOCH       4
# define LEAF       5

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_view
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}			t_view;

typedef struct s_pix
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	int		iter;
	int		color;
}			t_pix;

typedef struct s_all
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_view	view;

	int		type;

	double	zoom;
	double	x_offset;
	double	y_offset;

	double	julia_re;
	double	julia_im;

	int		iter;
}			t_all;

typedef struct s_line
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	int		color;
}	t_line;

typedef struct s_branch
{
	double	x;
	double	y;
	double	angle;
	double	length;
	int		depth;
	int		max_depth;
}	t_branch;

void		init_window(t_all *all);
void		init_view(t_view *v);
void		init_image(t_all *all);

int			is_valid_number(const char *s);
double		ft_atof(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		print_usage(void);

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

void		pixel_to_complex(int x, int y, t_all *all, t_pix *p);
void		mouse_to_complex(int x, int y, t_all *all, t_pix *p);

int			mandelbrot(double cr, double ci);
int			julia(double zr, double zi, t_all *all);

int			get_color(int iter);
int			newton_color(double zr, double zi, t_all *all);

void		draw_koch(t_all *all);
void		draw_leaf(t_all *all);
void		draw_fractal(t_all *all);

int			handle_key(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
int			close_w(void *param);
int			handle_esc_key(int keycode, void *param);
void	draw_tree(t_all *all);
#endif