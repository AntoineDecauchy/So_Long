/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:21:31 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/23 13:21:56 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "parsing.h"

char	**create_map(char *file_name, t_parse *parse)
{
	int		fd;
	int		i;
	char	*free_gnl;
	char	**map;

	i = 0;
	parse->number_line = number_line(file_name);
	fd = open(file_name, O_RDONLY);
	map = malloc((parse->number_line + 1) * sizeof(char *));
	while (i < parse->number_line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	free_gnl = get_next_line(fd);
	free(free_gnl);
	close(fd);
	parse->size_line = ft_strlen(map[0]);
	return (map);
}

void	first_parse(char **map, t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				parse->collectible++;
			else if (map[i][j] == 'E')
				parse->exit++;
			else if (map[i][j] == 'P')
			{
				parse->start++;
				parse->start_x = j;
				parse->start_y = i;
			}
			else if (map[i][j] != '\n' && map[i][j] != '0' && map [i][j] != '1')
				parse->intruder++;
			j++;
		}
		i++;
	}
}

void	second_parse(char **map, t_parse *parse)
{
	int		i;

	i = 0;
	parse->size_line = check_only_one(map[i], map);
	i++;
	while (i < (parse->number_line - 1))
	{
		if (check_one_border(map[i], map) != parse->size_line)
			exit_parse("Error Map : map is not a rectangle\n", map);
		i++;
	}
	if (check_only_one(map[i], map) != parse->size_line)
		exit_parse("Error Map : map is not a rectangle\n", map);
}

char	**create_parse_map(char *file_name)
{
	char	**map;
	t_parse	parse;

	init_parse(&parse);
	map = create_map(file_name, &parse);
	check_size_map(parse, map);
	first_parse(map, &parse);
	check_parse(parse, map);
	second_parse(map, &parse);
	printf("map ok \n");
	return (map);
}

int	main(void)
{
	char	**map;

	map = create_parse_map("../test.txt");
	free_map(map);
	return (0);
}
