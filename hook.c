/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:50:39 by marvin            #+#    #+#             */
/*   Updated: 2025/11/20 20:50:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ESC_KEY 65307

int handle_esc_key(int keycode, void *param)
{
    t_all *all = (t_all *)param;
    if (keycode == ESC_KEY)
    {
        mlx_destroy_image(all->mlx, all->img.img);
        mlx_clear_window(all->mlx, all->win);
        mlx_destroy_window(all->mlx, all->win);
        mlx_destroy_display(all->mlx);
        free(all->mlx);
        exit(0);
    }
    return (0);
}

int close_w(void *param)
{
    t_all *all = (t_all *)param;

    mlx_destroy_image(all->mlx, all->img.img);
    mlx_clear_window(all->mlx, all->win);
    mlx_destroy_window(all->mlx, all->win);
    mlx_destroy_display(all->mlx);
    free(all->mlx);
    exit(0);
    return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
    (void)x;
    (void)y;
    t_all *all = (t_all *)param;

    if (button == 4)
        all->zoom += 0.1;
    else if (button == 5 && all->zoom > 0.1)
        all->zoom -= 0.1;
    else
        return (0);

    draw_fractal(all);
    mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
    return (1);
}

int handle_key(int keycode, void *param)
{
    t_all *all = (t_all *)param;

    if (keycode == ESC_KEY)
        return handle_esc_key(keycode, all);

    if (keycode == 65361)
        all->x_offset -= 0.1;
    if (keycode == 65363) 
        all->x_offset += 0.1;
    if (keycode == 65364) 
        all->y_offset -= 0.1;
    if (keycode == 65362) 
        all->y_offset += 0.1;

    draw_fractal(all);
    mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
    return (0);
}

int close_window(void *param)
{
    return close_w(param);
}
