/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/06/09 15:14:37 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	extension(char *ext, char *str, int len)
{
	int		i;
	int		y;

	i = ft_strlen(str) - len;
	y = 0;
	if (i < 0)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ext[y] || (str[i] + 32) == ext[y])
			y++;
		else
			return (0);
		i++;
	}
	return (1);
}

int	open_fd(int fd, char *argv)
{
	fd = open(argv, O_DIRECTORY);
	if (fd != -1)
	{
		error_message("This is a directory", 0);
		exit(0);
	}
	if (access(argv, R_OK) == -1)
	{
		error_message("We dont have the right to read the file", 0);
		exit(0);
	}
	fd = open(argv, O_RDONLY);
	return (fd);
}

int	parsing(int ac, char **av, t_env *env)
{
	int	fd;
	int	stop;

	fd = 0;
	stop = 0;
	if (ac != 2)
		return (error_message("usage: [./cub3D.c] [map.cub]", 0));
	if (!extension(".cub", av[1], 4))
		return (error_message("bad file extension", 0));
	fd = open_fd(fd, av[1]);
	if (!(ft_check_file(fd)))
		return (error_message("file doesn't open", 0));
	read_file(fd, &env->nb_lfile, env, &stop);
	if (stop)
		return (0);
	if (env->nb_lfile != 6 || !env->texture.no_path || !env->texture.so_path \
		|| !env->texture.ea_path || !env->texture.we_path || \
		env->texture.f == 0 || env->texture.c == 0)
		return (error_message("miss params", 0));
	return (parsing_2(env, av[1]));
}

int	parsing_2(t_env *env, char *path)
{
	int	fd;
	int	exit;

	fd = 0;
	exit = 0;
	fd = open_fd(fd, path);
	(void)env;
	if (!(ft_check_file(fd)))
		return (error_message("file doesn't open", 0));
	read_map(fd, env, &exit);
	close (fd);
	if (exit)
		return (0);
	fd = open_fd(fd, path);
	if (!(ft_check_file(fd)))
		return (error_message("file doesn't open", 0));
	if (!open_map(env, fd))
		return (0);
	if (!ft_check_walls(env, env->map))
		return (0);
	if (!check_path_files(env))
		return (0);
	return (1);
}
