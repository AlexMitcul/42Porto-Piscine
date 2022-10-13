/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:25:27 by amitcul           #+#    #+#             */
/*   Updated: 2022/10/12 20:56:41 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_result
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	size;
}		t_result;

typedef struct s_map
{
	char	**symbols;
	int		**heat_map;
	int		rows;
	int		cols;
	char	empty_s;
	char	obstacle_s;
	char	full_s;
}				t_map;

# define TRUE 1
# define FALSE 0

char	*read_first_line(void);
char	**read_lines_from_stdin(int lines_count);

int		num_length(int n);
int		parse_first_line(t_map *map, char *line);
int		get_lines_count(char **lines);

/*		free.c		*/
void	free_map(t_map *map);
void	free_heatmap(t_map *map);
int		free_splitted_lines(char **splitted_lines);
void	**free_all_readed_lines(char **lines, int lines_count);
int		free_line(char *line);

/*		check_borders.c		*/
int		possible(t_map *map, t_result *res);

/*		file_works.c		*/
int		count_bytes(char *file_name);
char	*read_all_file(char *file_name, int bytes_count);
char	**get_data(char *filename);

/*		ft_atoi.c		*/
int		ft_atoi(const char *str);

/*		ft_putchar.c	*/
void	ft_putchar(char c);

/*		ft_putstr.c		*/
void	ft_putstr(char *str);

/*		ft_putchar_fd.c	*/
void	ft_putchar_fd(char c, int fd);

/*		ft_putstr_fd.c	*/
void	ft_putstr_fd(char *str, int fd);

/*		ft_putnbr.c		*/
void	ft_putnbr(int nb);

/*		int	ft_strlen(char *str)	*/
int		ft_strlen(const char *str);

/*		ft_split.c		*/
char	**ft_split(char *str, char *charset);

/*		ft_strdup.c		*/
char	*ft_strdup(char *src);

/*		heatmap.c		*/
int		build_heatmap(t_map *map);

/*		map.c			*/
int		init_map(t_map *map, char *filename);
int		parse_first_line(t_map *map, char *line);
void	copy_splitted_lines(t_map *map, char **splitted_lines);

/*		solve.c			*/
void	solve(t_map *map, char *filename);

/*		validate_map.c	*/
int		validate_map(t_map *map);

/*		is_printable.c	*/
int		is_printable(unsigned char c);
int		is_printable_str(char *str);
int		is_map_printable(t_map *map);

/*		print.c			*/
void	print_result(t_map *map, t_result *res);
void	print_heat_map(t_map *map);
void	print_map(t_map *map);
int		print_error(char *error);
void	print_structure(t_map *map);

/*		standart_input.c		*/
int		read_data_from_standart_input(t_map *map);

#endif
