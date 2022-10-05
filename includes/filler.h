/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:06:32 by okoponen          #+#    #+#             */
/*   Updated: 2022/08/16 15:35:33 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 1
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_filler
{
	int				player;
	int				cpu;
	int				x;
	int				y;
	int				**board;
	int				**piece;
	int				piece_x;
	int				piece_y;
	int				sum;
	int				final_x;
	int				final_y;
}				t_filler;

int		get_next_line(const int fd, char **line);
void	determine_map_size(t_filler *f, char *gnl_ret);
void	create_map(t_filler *f, int x, int y, int i);
void	determine_piece_size(t_filler *f);
void	get_piece(t_filler *f);
int		is_inside(t_filler *f, int x, int y);
int		board_has_empty_cells(t_filler *f);
int		fill_empty_cells(t_filler *f, int x, int y, int len);
int		heatmap_is_finished(t_filler *f, int curr, int len);
void	create_heatmap(t_filler *f);
int		print_final_coords(int y, int x);
int		check_cell(char c, t_filler *f, int x, int y);
int		only_one_touching(t_filler *f, int x, int y);
int		is_valid(t_filler *f, int x, int y);
int		check_sum(t_filler *f, int x, int y);
void	free_struct(t_filler *f);
int		place_piece(t_filler *f);

#endif
