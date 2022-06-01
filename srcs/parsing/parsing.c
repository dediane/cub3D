/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/06/01 12:23:49 by bben-yaa         ###   ########.fr       */
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

void	print_all(t_env *env)
{
	int	i;

	i = 0;
	printf("----------------------parinsing-------------------------------\n");
	printf("nb file after read is %d\n", env->nb_lfile);
	printf("Fin de la lecture du fichier\n");
	printf("alors on a ->\n");
	printf("north path :%s\n", env->texture.no_path);
	printf("south path :%s\n", env->texture.so_path);
	printf("east path  :%s\n", env->texture.ea_path);
	printf("weast path :%s\n", env->texture.we_path);
	printf("floor is    %d\n", env->texture.f);
	printf("floor color is %u\n", env->texture.fcl);
	printf("ceiling is  %d\n", env->texture.c);
	printf("ceiling color is %u\n", env->texture.ccl);
	printf("-----------------------------------------------------\n");
	while (env->map[i])
	{
		printf("la map :  [%s]\n", env->map[i]);
		i++;
	}
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
	print_all(env);
	return (1);
}
