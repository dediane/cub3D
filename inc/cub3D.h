/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:05:05 by ddecourt          #+#    #+#             */
/*   Updated: 2022/01/26 15:30:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_params
{
	void	*mlx;
	void	*mlx_win;
}				t_params;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
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
	int		fd_no;
	int		fd_so;
	int		fd_we;
	int		fd_ea;
}				t_texture;

typedef struct s_env
{
	char		**map;
	int			height;
	int			width;
	int			ppi;
	int			count;
	int			spawn_pos[2];
	int			ppos;
	t_params	params;
	t_img		img;
	t_texture	texture;
}				t_env;

//PARSING
//--check_map--
int	check_file_extension(char *map);
int	ft_check_map(char *path, t_env *env);
int check_around(char **map, int x, int y);
int	check_valid_char(t_env *env, char c, int x, int y);
int	check_wall_all_around(t_env *env, char **map);

//--check_texture--
int	ft_store_texture(char *path, char *line);
int	ft_check_texture(t_texture *texture, char *line);
int	ft_check_valid_files(t_texture *texture);

//--store_map--
int	is_empty(char *s);
int ft_store_map(char *path, t_env *env, int fd);

#endif
