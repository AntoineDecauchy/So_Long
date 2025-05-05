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

int	check_one_border(char *str, char **map)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] != '1' || str[len - 2] != '1')
		exit_parse("Error Map : Border fail\n", map);
	return (len);
}

void	check_size_map(t_parse parse, char **map)
{
	if (parse.number_line > 20 || parse.size_line > 20)
		exit_parse("Error map : To Big\n", map);
	if (parse.number_line < 3 || parse.size_line < 5)
		exit_parse("Error map : To Short\n", map);
}

void	check_parse(t_parse parse, char **map)
{
	if (parse.intruder != 0)
		exit_parse("Error Map : Intruder detected\n", map);
	if (parse.collectible == 0)
		exit_parse("Error Map : no collectible\n", map);
	if (parse.exit != 1)
		exit_parse("Error Map : no or more than one exit\n", map);
	if (parse.start == 0)
		exit_parse("Error Map : no or more than one start\n", map);
}
