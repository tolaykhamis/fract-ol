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

int	julia(double zr, double zi, double cr, double ci)
{
	int		i;
	double	tmp;

	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
