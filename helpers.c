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
	int	intensity;

	if (iter == MAX_ITER)
		return (0x000000);
	intensity = (int)(255.0 * iter / MAX_ITER);
	return ((intensity << 16) | (0 << 8) | intensity);
}

static int	get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

double	ft_atof(const char *s)
{
	double	result;
	double	divider;
	int		i;
	int		sign;

	result = 0.0;
	divider = 10.0;
	i = 0;
	sign = get_sign(s, &i);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result += (s[i] - '0') / divider;
		divider *= 10.0;
		i++;
	}
	return (result * sign);
}


void print_usage(void)
{
    write(1, "Usage:\n", 7);
    write(1, "  ./fractol mandelbrot\n", 24);
    write(1, "  ./fractol julia <real> <imag>\n", 33);
    exit(1);
}

