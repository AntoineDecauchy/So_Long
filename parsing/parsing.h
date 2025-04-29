/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 23:10:24 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/27 23:10:27 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct parse
{
	char	zero;
	char	one;
	char	collectible;
	char	exit;
	char	start;
	char	intruder;
	int		size_line;
	int		number_line;
}			t_parse;

void	init_parse(t_parse *parse);
int		number_line(char *file_name);
int		check_only_one(char *str, char **map);
int		check_one_border(char *str, char **map);
void	free_map(char **map);
void	exit_parse(char *error_message, char **map);

#endif
