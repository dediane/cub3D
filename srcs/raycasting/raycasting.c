#include "../inc/cub3D.h"

double pX = 10.5;
double pY = 10.5;

t_ray init_ray(t_rot * rot, double x, double y)
{
    t_ray ray;
    if (rot->cos > 0)
        ray.cos_step.x =
}

void    raycasting(t_env *env, t_img *img)
{
    int s_width;
    int s_height;

    s_width = 5;
    s_height = 5;
    t_rot rot;
    rot.angle = M_PI * -.88;
    rot.cos = cos(rot.angle);
    rot.sin = sin(rot.angle);

    t_ray ray;
    ray = init_ray(&rot, pX, pY);
}