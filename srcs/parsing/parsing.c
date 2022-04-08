/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:33:32 by user42            #+#    #+#             */
/*   Updated: 2022/04/08 12:45:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	error_message(char *str, int ret)
{
	ft_pustr("Error: ");
	ft_putstr(str);
	ft_putstr("\n");
	return (ret);	
}

int	parsing(int ac, char **av, t_env *env)
{
	if (ac != 2)
		return (error_message("usage: [./cub3D.c] [map.cub]", 0));
	if (!(ft_check_map(av[1], &env)))
		return (error_message("invalid char in map.", 0));
	return (1);
}