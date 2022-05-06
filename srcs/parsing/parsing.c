/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/05/06 17:03:01 by bben-yaa         ###   ########.fr       */
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
	(void)av;
	(void)env;
	if (ac != 2)														// check arg
		return (error_message("usage: [./cub3D.c] [map.cub]", 0));
	if (!extension(".cub", av[1], 4))										// check extension
		return (error_message("bad file extension", 0));
	fd = open_fd(fd, av[1]);											// open fd (en vrai cette fonction elle sert a rien)
	if (!(ft_check_file(fd)))											// check open fd
		return (error_message("file doesn't open", 0));
	printf("nb file before is %d\n", env->nb_lfile);
	read_file(fd, &env->nb_lfile, env, &stop);
	printf("nb file after is %d\n", env->nb_lfile);
	if (stop)
	{
		ft_free(env);
		exit(0);
	}
	// here check les nom (NO, SO, ...) et leur extension et si le fichier s'ouvre
	return (1);
}