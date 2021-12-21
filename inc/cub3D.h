/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:05:05 by ddecourt          #+#    #+#             */
/*   Updated: 2021/12/21 00:35:23 by ddecourt         ###   ########.fr       */
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
# include "mlx/mlx.h"
# include "libft/libft.h"

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
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
}				t_texture;

typedef struct s_env
{
	char		**map;
	int			height;
	int			width;
	int			ppi;
	int			count;
	t_params	params;
	t_img		img;
	t_texture	textures;
}				t_env;

#endif
