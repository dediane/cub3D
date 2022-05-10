/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:16:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/10 08:58:17 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_num(char *line)
{
	int	i;
	int j;
	int	num;

	i = 0;
	j = 0;
	pass_space(line, &i);
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	pass_space(line, &i);
	if (line[i] == ',')
		return (0);
	while(line[i] && j <= 2)
	{
		pass_space(line, &i);
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' && line[i + 1] && line[i + 1]  >= '0' && line[i + 1] <= '9' ))
		{
			while((line[i] && line[i] >= '0' && line[i] <= '9') || (line[i] == '-' && line[i + 1] && line[i + 1]  >= '0' && line[i + 1] <= '9' ))
				i++;
			j++;
			num++;
		}
		else if ((line[i] == ',' || line[i] == '\n') && num == 1)
		{
			i++;
			num = 0;
		}
		else
			return (0);
		if (num == 2)
			return(0);
	}
	if (j < 3)
		return (0);
	return (1);
}
