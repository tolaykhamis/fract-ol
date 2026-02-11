/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:45:20 by marvin            #+#    #+#             */
/*   Updated: 2025/11/20 20:45:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

int	get_color(int iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (0x000000);
	
	t = (double)iter / (double)MAX_ITER;
	t = t * 6.0;
	
	if (t < 1.0) 
		r = 0, g = (int)(255 * t), b = 255;
	else if (t < 2.0) 
		r = 0, g = 255, b = (int)(255 * (2.0 - t));
	else if (t < 3.0)
		r = (int)(255 * (t - 2.0)), g = 255, b = 0;
	else if (t < 4.0)
		r = 255, g = (int)(255 * (4.0 - t)), b = 0;
	else if (t < 5.0)
		r = 255, g = 0, b = (int)(255 * (t - 4.0));
	else
		r = (int)(255 * (6.0 - t)), g = 0, b = 255;
	return ((r << 16) | (g << 8) | b);
}

double	ft_atof(const char *s)
{
	double	res = 0.0;
	double	pow = 1.0;
	int		sign = 1;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
		res = res * 10.0 + (*s++ - '0');
	if (*s == '.')
	{
		while (*++s >= '0' && *s <= '9')
		{
			res = res * 10.0 + (*s - '0');
			pow *= 10.0;
		}
	}
	return (sign * res / pow);
}

void	print_usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 24);
	write(1, "  ./fractol julia <real> <imag>\n", 33);
	write(1, "  ./fractol leaf\n", 17);
	exit(1);
}