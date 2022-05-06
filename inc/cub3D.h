/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:05:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/06 16:59:19 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 0xff1b
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"


//maps de test avant parsing
//char mapi[20][20];

typedef struct s_params
{
	void	*mlx;
	void	*mlx_win;
	int		res_x;
	int		res_y;
}				t_params;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		ratio;
}			t_img;

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	no_texture;
	t_img	so_texture;
	t_img	we_texture;
	t_img	ea_texture;
	int		fd_no;
	int		fd_so;
	int		fd_we;
	int		fd_ea;
}				t_texture;

//pour gérer les rotations
typedef struct s_rot
{
	double angle;
	double cos;
	double sin;
}				t_rot;

//vecteurs
typedef struct s_vec
{
	int x;
	int y;
}				t_vec;

typedef struct s_vecdouble
{
	double x;
	double y;
}				t_vecdouble;

typedef struct s_shape
{
	int x;
	int y;
	int width;
	int height;
}				t_shape;

//structure d'intervalle du raycasting
typedef struct s_ray
{
	t_vecdouble		cos_step;
	t_vecdouble 	sin_step;
	double		len_cos;
	double		len_sin;
}				t_ray;

typedef struct s_env
{
	char		map[20][20];
	int			nb_lfile;
	int			height;
	int			width;
	int			ppi;
	int			count;
	int			spawn_pos[2];
	int			ppos;
	t_params	params;
	t_img		img;
	t_texture	texture;
	t_ray		ray;
	t_rot		rot;
	t_vec		vec;
	t_vecdouble	vecdouble;
}				t_env;

// GET NEXT LINE
//--get_next_line_utils--
char	*copy(char *s1, int *i, char *ret);

//--get next line--
int		ft_strclen(char *str, char c);
char	*ft_ret_str(char **ret_str);
char	*gnl(int fd, int *p, bool first_read);


// PARSING
//--parsing--
int		error_message(char *str, int ret);
int		extension(char *ext, char *str, int len);
int		open_fd(int fd, char *argv);
int		parsing(int ac, char **av, t_env *env);

//--check_map--
int		ft_check_file(int fd);
int		check_around(char map[20][20], int x, int y);
int		check_valid_char(t_env *env, char c, int x, int y);
int		check_wall_all_around(t_env *env, char **map);

//--check_texture--
int		ft_store_texture(char **path, char *line);
int		ft_check_texture(t_texture *texture, char *line);
int		load_all_textures(t_env *env);

//--store_map--
int		is_empty(char *s);
int		ft_store_map(char *path, t_env *env, int fd);

//--malloc_map--
void	secure_line(char *line);
void	read_file(int fd, int *nb_line, t_env *env, int *stop);

//--init_env--
void	init_env(t_env *env);
void	init_texture(t_texture *texture);
void	ft_free(t_env *env);



// SRCS
//--win_utils--
int		quit_program(t_env *env);
int		keypress(int key, t_env *env);

//--raycasting--
t_ray	init_ray(t_rot * rot, double x, double y);
void	raycasting(t_env *env, t_img *img);
int		render_next_frame(t_env *env);
void	cast_forward(t_ray *ray, t_ray step);

//--raycasting_utils--
void	get_pixel(t_img *img, int x, int y);
void	set_pixel(t_img *img, int x, int y, int color);
void	rect(t_img *img, t_shape shape, int color);
double	calc_sqrtlen(t_vecdouble v);
void    draw_map(t_env *env, t_img *img);


#endif
