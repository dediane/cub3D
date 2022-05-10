/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/05/10 12:19:57 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	error_message(char *str, int ret)
{
	printf("Error: %s\n", str);
	return (ret);	
}

int	extension(char *ext, char *str, int len)	//check extension en maj ou en miniscule 
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
	fd = open(argv, O_RDONLY);
	return (fd);
}

int	parsing(int ac, char **av, t_env *env)
{
	int	fd;
	int stop;

	fd = 0;
	stop = 0;
	if (ac != 2)														// check arg
		return (error_message("usage: [./cub3D.c] [map.cub]", 0));
	if (!extension(".cub", av[1], 4))										// check extension
		return (error_message("bad file extension", 0));
	fd = open_fd(fd, av[1]);											// open fd (en vrai cette fonction elle sert a rien)
	if (!(ft_check_file(fd)))											// check open fd
		return (error_message("file doesn't open", 0));
	printf("nb file before is %d\n", env->nb_lfile);
	read_file(fd, &env->nb_lfile, env, &stop);
	printf("nb file after read is %d\n\n", env->nb_lfile);
	printf("Fin de la lecture du fichier\n");
	printf("alors on a ->\n");
	printf("north path :%s", env->texture.no_path);
	printf("south path :%s", env->texture.so_path);
	printf("east path  :%s", env->texture.ea_path);
	printf("weast path :%s", env->texture.we_path);
	printf("floor is    %d\n", env->texture.f);
	printf("floor color is %u\n", env->texture.fcl);
	printf("ceiling is  %d\n", env->texture.c);
	printf("ceiling color is %u\n", env->texture.ccl);
	if (stop || !env->texture.no_path || !env->texture.so_path \
		|| !env->texture.ea_path || !env->texture.we_path || env->texture.f == 0 || env->texture.c == 0 || env->nb_lfile != 6)
	{
		printf("nb line %d\n", env->nb_lfile);
		printf("I AM IN RETURN 0 IN PARSING\n");
		return (0);
	}
	// here check les nom (NO, SO, ...) et leur extension et si le fichier s'ouvre
	return (1);
}