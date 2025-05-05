/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:12:42 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/28 22:12:43 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "parsing.h"

int	number_line(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	init_parse(t_parse *parse)
{
	parse->collectible = 0;
	parse->exit = 0;
	parse->start = 0;
	parse->intruder = 0;
	parse->start_x = 0;
	parse->start_y = 0;
	parse->size_line = 0;
	parse->number_line = 0;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	exit_parse(char *error_message, char **map)
{
	free_map(map);
	putstr(error_message);
	exit(EXIT_FAILURE);
}

int	check_only_one(char *str, char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		if (str[i] != '1')
			exit_parse("Error Map : Border fail\n", map);
		i++;
	}
	return (len);
}
