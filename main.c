/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:31:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/16 15:31:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_number(const char *s)
{
	int	i;
	int	has_digits;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	has_digits = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		has_digits = 1;
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		has_digits = 1;
		i++;
	}
	return (s[i] == '\0' && has_digits);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static void	parse_args(int ac, char **av, t_all *all)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		all->type = MANDELBROT;
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
	{
		if (!is_valid_number(av[2]) || !is_valid_number(av[3]))
			print_usage();
		all->type = JULIA;
		all->julia_re = ft_atof(av[2]);
		all->julia_im = ft_atof(av[3]);
	}
	else if (ac == 2 && ft_strcmp(av[1], "leaf") == 0)
		all->type = LEAF;
	else
		print_usage();
}

void	init_image(t_all *all)
{
	all->img.img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if (!all->img.img)
		exit(1);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bpp,
			&all->img.line_len, &all->img.endian);
}

int	main(int ac, char **av)
{
	t_all	all;

	all.zoom = 1.0;
	all.x_offset = 0.0;
	all.y_offset = 0.0;
	all.iter = MAX_ITER;
	all.julia_re = 0.0;
	all.julia_im = 0.0;
	parse_args(ac, av, &all);
	init_window(&all);
	init_image(&all);
	init_view(&all.view);
	draw_fractal(&all);
	mlx_put_image_to_window(all.mlx, all.win, all.img.img, 0, 0);
	mlx_mouse_hook(all.win, mouse_hook, &all);
	mlx_key_hook(all.win, handle_key, &all);
	mlx_hook(all.win, 17, 0, close_w, &all);
	mlx_loop(all.mlx);
	return (0);
}