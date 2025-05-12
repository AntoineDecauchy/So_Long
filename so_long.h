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

# include "mlx.h"
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

char	**create_parse_map(char *file_name, int *x, int *y);

typedef struct image
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collectible;
	void	*cartman;
}			t_image;

typedef struct map
{
	int		x_size;
	int		y_size;
}			t_map;

void	draw_square(void *mlx, void *win, int x, int y, int side, int color);
void	load_image(void *mlx, t_image *image);
void	draw_item(void *mlx, void *win, char c, int x, int y, t_image image);
void	draw_map(void *mlx, void *win, char **map, t_image image);

#endif
