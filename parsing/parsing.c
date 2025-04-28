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

	parse->number_line = number_line(file_name);
	if (parse->number_line < 3)
	{
		putstr("Error Map : Insufficient number of lines\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
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
	return (map);
}

void	first_parse(char **map, t_parse *parse)
{
	char	*line;
	char	**row;

	row = map;
	while(*row)
	{
		line = *row;
		while (*line)
		{
			if (*line == '0')
				parse->zero++;
			else if (*line == '1')
				parse->one++;
			else if (*line == 'C')
				parse->collectible++;
			else if (*line == 'E')
				parse->exit++;
			else if (*line == 'P')
				parse->start++;
			else if (*line != '\n')
				parse->intruder++;
			line++;
		}
		row++;
	}
}

void	check_parse(t_parse parse, char **map)
{
	if (parse.intruder != 0)
		exit_parse("Error Map : Intruder detected\n", map);
	if (parse.zero == 0)
		exit_parse("Error Map : no 0\n", map);
	if (parse.one == 0)
		exit_parse("Error Map : no 1\n", map);
	if (parse.collectible == 0)
		exit_parse("Error Map : no collectible\n", map);
	if (parse.exit != 1)
		exit_parse("Error Map : no or more than one exit\n", map);
	if (parse.start == 0)
		exit_parse("Error Map : no or more than one start\n", map);
}

void	second_parse(char **map, t_parse *parse)
{
	int		i;
	char	*line;

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

	parse = init_parse(parse);
	map = create_map(file_name, &parse);
	first_parse(map, &parse);
	check_parse(parse, map);
	second_parse(map, &parse);
	printf("map ok \n");
	return (map);
}

int main(void)
{
	char **map = create_parse_map("../test.txt");
	free_map(map);
	return 0;
}
