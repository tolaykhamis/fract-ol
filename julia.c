/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:44:17 by marvin            #+#    #+#             */
/*   Updated: 2025/11/20 20:44:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zr, double zi, t_all *all)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < all->iter)
	{
		tmp = zr * zr - zi * zi + all->julia_re;
		zi = 2 * zr * zi + all->julia_im;
		zr = tmp;
		iter++;
	}
	return (iter);
}

