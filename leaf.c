#include "fractol.h"
#include <math.h>

static void	draw_line(t_all *all, t_line l)
{
	double	dx;
	double	dy;
	int		steps;
	int		i;

	dx = l.x2 - l.x1;
	dy = l.y2 - l.y1;
	steps = (int)fabs(dx);
	if (fabs(dy) > fabs(dx))
		steps = (int)fabs(dy);
	if (steps <= 0)
		return ;
	dx /= steps;
	dy /= steps;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(&all->img, (int)l.x1, (int)l.y1, l.color);
		l.x1 += dx;
		l.y1 += dy;
		i++;
	}
}

static int	branch_color(int depth, int max_depth)
{
	int	ratio;
	int	r;
	int	g;
	int	b;

	ratio = (depth * 255) / max_depth;
	r = (ratio * 101) / 255;
	g = 255 - ratio;
	b = (ratio * 33) / 255;
	return ((r << 16) | (g << 8) | b);
}

static void	draw_branch_line(t_all *all,
	t_branch b, double x_end, double y_end)
{
	t_line	line;

	line.x1 = b.x;
	line.y1 = b.y;
	line.x2 = x_end;
	line.y2 = y_end;
	line.color = branch_color(b.depth, b.max_depth);
	draw_line(all, line);
}

static void	draw_branch(t_all *all, t_branch b)
{
	double		x_end;
	double		y_end;
	t_branch	next;

	if (b.depth <= 0 || b.length < 0.5)
		return ;
	x_end = b.x + cos(b.angle) * b.length;
	y_end = b.y + sin(b.angle) * b.length;
	draw_branch_line(all, b, x_end, y_end);
	next.x = x_end;
	next.y = y_end;
	next.depth = b.depth - 1;
	next.max_depth = b.max_depth;
	next.angle = b.angle;
	next.length = b.length * 0.70;
	draw_branch(all, next);
	next.angle = b.angle + 25 * M_PI / 180;
	next.length = b.length * 0.65;
	draw_branch(all, next);
	next.angle = b.angle - 25 * M_PI / 180;
	draw_branch(all, next);
}
void	draw_tree(t_all *all)
{
	t_branch	root;
	double		scale;

	scale = all->zoom;
	if (scale < 0.1)
		scale = 0.1;

	root.x = WIDTH / 2.0 + all->x_offset;
	root.y = HEIGHT - 50.0 + all->y_offset;
	root.angle = -M_PI / 2.0;
	root.length = 120.0 * scale;
	root.depth = 10;
	root.max_depth = 10;
	draw_branch(all, root);
}
