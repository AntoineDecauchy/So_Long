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
# include "./keybind/key.h"
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/*-----libft-----*/

char	*get_next_line(int fd);
void	putstr(char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t lendst);
char	*ft_strndup(const char *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
void	free_map(char **map);

#endif
