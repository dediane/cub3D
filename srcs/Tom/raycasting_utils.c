#include "../inc/cub3D.h"

/*void	get_pixel(t_img *img, int x, int y)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return *(int*)dst;
}*/

void	set_pixel(t_img *img, int x, int y, int color)
{
	char *dst;

	if (x < 0 || y < 0)
		return;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	rect(t_img *img, t_shape shape, int color)
{
	int i;
	int j;

	i = shape.x;
	while (i < shape.x + shape.width && i < img->width)
	{
		j = shape.y;
		while ( j < shape.y + shape.height && j < img->height)
		{
			set_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

double calc_sqrtlen(t_vecdouble v)
{
	return (v.x * v.x + v.y * v.y);
}

void    draw_map(t_env *env, t_img *img)
{
	(void)env;
	int x;
	int y;
	t_shape shape;

	shape.width = 19;
	shape.height = 19;
	x = 0;
	while (x < 20)
	{
		y = 0;
		while (y < 20)
		{
			if (env->map[x][y])
			{
				shape.x = 100 + x * 20;
				shape.y = 100 + y * 20;
				rect(img, shape, 0x00FFFFFF);
			}
			else
			{
				shape.x = 100 + x * 20;
				shape.y = 100 + y * 20;
				rect(img, shape, 0x0029292B);
			}
			y++;
		}
		x++;
	}
}