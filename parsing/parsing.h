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
	int		size;
}			t_parse;

#endif
