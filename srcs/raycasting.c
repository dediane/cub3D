#include "../inc/cub3D.h"

double pX = 10.5;
double pY = 10.5;
double yaw = M_PI * -.88;

t_ray init_ray(t_rot * rot, double x, double y)
{
	t_ray	ray;

	if (rot->cos > 0)
		ray.cos_step.x = floor(x) - x + 1;
	else
		ray.cos_step.x = ceil(x) - x - 1;
	ray.cos_step.y = ray.cos_step.x * (rot->sin / rot->cos);
	ray.len_cos = calc_sqrtlen(ray.cos_step);
	if (rot->sin > 0)
		ray.sin_step.y = floor(y) - y + 1;
	else
		ray.sin_step.y = ceil(y) - y - 1;
	ray.sin_step.x = ray.sin_step.y * (rot->cos / rot->sin);
	ray.len_sin = calc_sqrtlen(ray.sin_step);
	return (ray);
}

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->len_cos < ray->len_sin)
	{
		ray->cos_step.x += step.cos_step.x;
		ray->cos_step.y += step.cos_step.y;
		ray->len_cos += step.len_cos;
	}
	else
	{
		ray->sin_step.x += step.sin_step.x;
		ray->sin_step.y += step.sin_step.y;
		ray->len_sin += step.len_sin;
	}
}

int		check_colide(t_ray ray, t_rot rot, int up)
{
	int posX;
	int posY;

	//int shiftX;
	//int shiftY;

	if (up)
	{
		posX = floor(pX + ray.sin_step.x);
		posY = floor(pY + ray.sin_step.y);
		if (rot.sin < 0)
			posY--;
	}
	else
	{
		posX = floor(pX + ray.cos_step.x);
		posY = floor(pY + ray.cos_step.y);
		if (rot.cos < 0)
			posX--;
	}

	if (posX < 0 || posX > 19 || posY < 0 || posY > 19)
		return 0;
	return (map[posX][posY] > 0);
}

void raycasting(t_env *env, t_img *img)
{
	t_rot rot;

	yaw += 0.01f;

	int x = 0;
	while (x < env->params.res_x)
	{

		double c = (x / (float)env->params.res_x) - 0.5;
		double newa = atan2(c, 0.6);

		rot.angle = yaw + newa;
		rot.cos = cos(rot.angle);
		rot.sin = sin(rot.angle);

		t_ray ray = init_ray(&rot, pX, pY);
		t_ray step = init_ray(&rot, 0, 0);


		int i = 0;

		t_shape line;
		line.width = 1;
		line.x = x;

		while (i < 20)
		{
			if (check_colide(ray, rot, ray.len_cos > ray.len_sin))
			{
				double len = fmin(ray.len_cos, ray.len_sin);

				line.height = env->params.res_y / (len * cos(newa));
				line.y = (env->params.res_y - line.height) / 2;
				rect(img, line, 0x00FFFFFF);
				break;
			}
			cast_forward(&ray, step);
			i++;
		}
		x++;
	}

}

int     render_next_frame(t_env *env)
{
	t_shape shape;

	shape.width = env->params.res_x;
	shape.height = env->params.res_y;
	shape.x = 0;
	shape.y = 0;
	rect(&(env->img), shape, 0x00000000);

	raycasting(env, &(env->img));

    mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->img.img, 0, 0);
    mlx_do_sync(env->params.mlx);

	return 0;
}

/*void	raycasting(t_env *env, t_img *img)
{
	(void)env;
	t_shape shape;
	t_rot rot;
	t_ray step;
	t_ray ray;
	int i = 0;

	shape.width = 5;
	shape.height = 5;
	rot.angle = yaw;
	rot.cos = cos(rot.angle);
	rot.sin = sin(rot.angle);
	//intervalle du raycasting
	ray = init_ray(&rot, pX, pY);
	step = init_ray(&rot, 0, 0);
	//check en alternance vertical et horizontal
	while ( i < 20)
	{
		if (ray.len_cos < ray.len_sin)
		{
			//intersection
			shape.x = 100 + pX * 20 + ray.cos_step.x * 20;
			shape.y = 100 + pY * 20 + ray.cos_step.y *20;
			rect(img, shape, 0x0000FF00);
			//ajout petite intervalle a l'intervalle totale
			ray.cos_step.x += step.cos_step.x;
			ray.cos_step.y += step.cos_step.y;
			ray.len_cos += step.len_cos;
		}
		else
		{
			shape.x = 100 + pX * 20 + ray.sin_step.x * 20;
			shape.y = 100 + pY * 20 + ray.sin_step.y * 20;
			rect(img, shape, 0X00FFFF00);
			ray.sin_step.x += step.sin_step.x;
			ray.sin_step.y += step.sin_step.y;
			ray.len_sin += step.len_sin;
		}
		i++;
	}
}

int render_next_frame(t_env *env)
{
	yaw += 0.001f;

	t_shape shape;
	shape.width = 600;
	shape.height = 600;
	shape.x = 0;
	shape.y = 0;
	rect(&(env->img), shape, 0x00000000);

	draw_map(env, &(env->img));
	raycasting(env, &(env->img));

	mlx_put_image_to_window(env->params.mlx, env->params.mlx_win, env->img.img, 0, 0);
	mlx_do_sync(env->params.mlx);
	return (0);
}*/
