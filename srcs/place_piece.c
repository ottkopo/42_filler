/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:21:10 by okoponen          #+#    #+#             */
/*   Updated: 2022/08/17 13:21:49 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*check that the current placement is touching only one of my currently placed pieces*/
int	only_one_touching(t_filler *f, int x, int y)
{
	int	i;
	int	j;
	int	touching;

	i = 0;
	j = 0;
	touching = 0;
	while (j < f->piece_y)
	{
		while (i < f->piece_x)
		{
			if (f->piece[j][i] == f->player)
			{
				if (f->board[y + j][x + i] == f->player)
					touching++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (touching != 1)
		return (0);
	return (1);
}
/*checking if the placement to given coordinates is valid by making sure that the piece is not going over any pieces currently
on the board or it is not being placed outside of the map. Also checking that the current placement is connected to my own pieces*/
int	is_valid(t_filler *f, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x > f->x || y > f->y || x < 0 || y < 0)
		return (0);
	while (j < f->piece_y)
	{
		while (i < f->piece_x)
		{
			if (f->piece[j][i] == f->player)
			{			
				if (i + x >= f->x || j + y >= f->y)
					return (0);
				if (f->board[y + j][i + x] < 0 && f->board[y + j][i + x] \
					!= f->player)
					return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (only_one_touching(f, x, y));
}

/*check the sum of a valid placement. Lower sum is better. Sum is counted by adding up every value from the heatmap that
the current block would cover in this certain placement*/
int	check_sum(t_filler *f, int x, int y)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	j = 0;
	sum = 0;
	while (j < f->piece_y)
	{
		while (i < f->piece_x)
		{
			if (f->piece[j][i] == f->player)
			{
				if (f->board[y + j][x + i] > 0)
					sum = sum + f->board[y + j][x + i];
				if (f->board[y + j][x + i] == 0)
					sum = sum + 1000;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (sum);
}

/*function to free the struct at the end of the program*/
void	free_struct(t_filler *f)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < f->piece_y)
	{
		free (f->piece[j]);
		j++;
	}
	while (i < f->y)
	{
		free(f->board[i]);
		i++;
	}
	free (f->board);
	free (f->piece);
	f->x = 0;
	f->y = 0;
	f->piece_x = 0;
	f->piece_y = 0;
	f->sum = 0;
	f->final_x = 0;
	f->final_y = 0;
}

/*function to determine the best placement for current piece by parsing through every cell and saving the "sum" of every valid placement
and saving the coordinates for evvery placement that is better than the current best"
int	place_piece(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	f->sum = 999999;
	while (y < f->y)
	{
		while (x < f->x)
		{
			if (is_valid(f, x, y))
			{
				if (check_sum(f, x, y) < f->sum)
				{
					f->sum = check_sum(f, x, y);
					f->final_x = x;
					f->final_y = y;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (print_final_coords(f->final_y, f->final_x));
}
