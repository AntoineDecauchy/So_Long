/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:46 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/23 12:46:05 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

//# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

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

/*-----get_next_line-----*/

size_t	checkn(char *src);
char	*end(char **tmp, char **buffer);
char	*get_next_line(int fd);
void	putstr(char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t lendst);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
