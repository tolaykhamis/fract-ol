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

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
#include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_view {
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_view;

typedef struct s_all
{
    void    *mlx;
    void    *win;
    t_img   img;
    t_view  view;

    int     type;     
    double  julia_re;
    double  julia_im;

    double  zoom;     
    double  x_offset; 
    double  y_offset;
}   t_all;


int		close_w(void *param);
int		handle_key(int key, void *param);
int		mouse_hook(int button, int x, int y, void *param);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

void	init_view(t_view *v);
void    pixel_to_complex(int x, int y, t_view *v, double *cr, double *ci, t_all *all);
void	mouse_to_complex(int x, int y, t_view *v, double *cr, double *ci);

int		mandelbrot(double cr, double ci);
int		julia(double zr, double zi, double cr, double ci);
int		get_color(int iter);

int		ft_strcmp(const char *s1, const char *s2);
double	ft_atof(const char *s);
void	print_usage(void);
int is_valid_number(const char *s);
void	draw_fractal(t_all *all);

#endif