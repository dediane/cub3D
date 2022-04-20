/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 13:21:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	error_message(char *str, int ret)
{
	printf("Error: %s\n", str);
	return (ret);	
}

int	extention(char *ext, char *str)
{
	int		i;
	int		y;

	i = ft_strlen(str) - 4;
	y = 0;
	if (i < 0)
		return (0);
	while (str[i])
	{
		if (str[i] == ext[y] || (str[i] + 32) == ext[y])
			y++;
		else
			return (0);
		i++;
	}
	return (1);	
}

int	open_fd(int *fd, char **argv)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
		return (0);
	return (1);
}

int	parsing(int ac, char **av, t_env *env)
{
	int	*fd;

	fd = 0;
	(void)env;
	if (ac != 2)
		return (error_message("usage: [./cub3D.c] [map.cub]", 0));
	if (!extention(".cub", av[1]))
		return (error_message("bad file extention", 0));
	if (!open_fd(fd, av))
		return (error_message("file doesn't open", 0));
	/*if (!(ft_check_map(av[1], &env)))
		return (error_message("invalid char in map.", 0));*/
	return (1);
}