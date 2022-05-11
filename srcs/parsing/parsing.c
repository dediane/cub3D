/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/05/11 14:06:33 by bben-yaa         ###   ########.fr       */
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
	int stop;

	fd = 0;
	stop = 0;
	if (ac != 2)															// check arg
		return (error_message("usage: [./cub3D.c] [map.cub]", 0));
	if (!extension(".cub", av[1], 4))										// check extension
		return (error_message("bad file extension", 0));
	fd = open_fd(fd, av[1]);												// check directory, right access and open file
	if (!(ft_check_file(fd)))												// check open fd
		return (error_message("file doesn't open", 0));
	read_file(fd, &env->nb_lfile, env, &stop);								// check all params, bad char in map
	if (stop)
		return (0);
	if (env->nb_lfile != 6|| !env->texture.no_path || !env->texture.so_path \
		|| !env->texture.ea_path || !env->texture.we_path || \
		env->texture.f == 0 || env->texture.c == 0)
		return (error_message("miss params", 0));
			// on peut checker l'access des files textures
	/*		if (!check_file(&env->texture))
				return (error_message("We can't use the texture's files", 0));
	*/
	// ici on cherche le nb max de la map
	// on stock la map et on remplace les spaces par des '0'
	// on check si la map est valide
	// 		L-> si elle est fermé, un seul perso

	
	printf("nb file after read is %d\n", env->nb_lfile);
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
	return (1);
	//return (parsing_2(env, av[1]));
}

int	parsing_2(t_env *env, char *path)
{
	int	fd;

	fd = 0;
	fd = open_fd(fd, path);												// check directory, right access and open file
	if (!(ft_check_file(fd)))												// check open fd
		return (error_message("file doesn't open", 0));
	if (!read_map(fd, env))
		return(0);
	return (1);
}

//A ENLEVER QUAND ON PUSH 
/******

	Dans le parsing de la map, on accepte:	les espaces ' '
											'1'; '0'; 'N'
											'E'; 'W'; 'S'

	et dans le parsing de des params (NO text, SO text, EA text, WE text, F col, C col)
											les espaces ' '
											','; '\t' tabs et  
											

******/