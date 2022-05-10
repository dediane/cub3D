/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:44:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/10 14:54:04 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3D.h"

int	is_empty(char *s)
{
	int i;

	i = 0;
	if (s[0] == '\n' && !(s[1]))
		return (1);
	while (s[i])
		if ((ft_isprint(s[i])))
			i++;
	if (i == ft_strlen(s))
		return (1);
	else
		return (0);
}

int ft_store_map(char *path, t_env *env, int fd)
{
	char	*line;
	int		flag;
	int		height;
	
	flag = 0;
	height = 0;
	(void)path;
	while (get_next_line(fd, &line) > 0)
	{
		if (flag < 4)
		{
			if (ft_check_texture(&env->texture, line))
				flag++;
		}
		if (flag == 4)
		{
			load_all_textures(env);
			flag++;
		}
		if (flag > 4)
		{
			if (!(is_empty(line)))
				height++;
			else
				flag++;
		}
	}
	return (1);
}

int	is_map(char *line)
{
	int i;

	i = 0;
	printf("Dans is map pour line :\n%s\n\n", line);
	while (line[i])
	{
		pass_space(line, &i);
		if (line[i] == '\n')
		{
			printf("we are in a backslach n donc we dont care!\n");
			return (1);			// dans la ligne il a rien
		}
		else if (line[i] == '1')
		{
			while(line[i])
			{
				if (line[i] == '1' || line[i] == '0' || \
					line[i] == ' ' || line[i] == 'N' || \
					line[i] == 'S' || line[i] == 'E' || \
					line[i] == 'W' || line[i] == '\n')
					i++;
				else
				{
					printf("The bad char is %c et i %d\n", line[i], i);
					return (error_message("bad char hihi, i catch you!", 0));
				}
			}
			printf("bon c'est bon on a fini de lire\n");
			return (1);
		}
		else
		{
			printf("DEJA les murs ne sont pas fermé et de DEUX tu fous quoi la //%c// pour i = %d\n", line[i], i);
			return (error_message("PT2 : -> bad char hihi, i catch you!\n", 0));	
		}
		i++;
	}
	printf("GGGGGGOOOOOOOOOOOOODDDDD\n");
	printf("OKay c'est good pour cette line\n%s", line);
	printf("GGGGGGOOOOOOOOOOOOODDDDD\n");
	return (1);
}
