/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:35:10 by okoponen          #+#    #+#             */
/*   Updated: 2022/08/19 15:35:59 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*function to check that a cell is not outside the map*/
int	is_inside(t_filler *f, int x, int y)
{
	if (y < 0)
		return (0);
	if (y >= f->y)
		return (0);
	if (x < 0)
		return (0);
	if (x >= f->x)
		return (0);
	return (1);
}

/*check if there are no more empty cells in the map*/
int	board_has_empty_cells(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < f->y)
	{
		while (x < f->x)
		{
			if (f->board[y][x] == 0)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

/*function to fill empty cells around found value*/
int	fill_empty_cells(t_filler *f, int x, int y, int len)
{
	int	i;
	int	j;
	int	filled;

	i = -1;
	j = -1;
	filled = 0;
	while (j <= 1)
	{
		while (i <= 1)
		{
			if (is_inside(f, (x + i), (y + j)))
			{
				if (f->board[y + j][x + i] == 0)
				{
					f->board[y + j][x + i] = len;
					filled++;
				}
			}
			i++;
		}
		i = -1;
		j++;
	}
	return (filled);
}

/*insert heat values to the map by parsing through the map looking for a certain value and filling all empty cells around that value
with a value that is 1 higher than the current value*/
int	heatmap_is_finished(t_filler *f, int curr, int len)
{
	int	x;
	int	y;
	int	filled;

	x = 0;
	y = 0;
	filled = 0;
	while (y < f->y)
	{
		while (x < f->x)
		{
			if (f->board[y][x] == curr)
				filled = filled + fill_empty_cells(f, x, y, len);
			x++;
		}
		x = 0;
		y++;
	}
	if (filled == 0)
		return (1);
	return (0);
}

/*read empty map and add heatmap values to empty cells*/
void	create_heatmap(t_filler *f)
{
	int	x;
	int	y;
	int	len;
	int	curr;

	x = 0;
	y = 0;
	len = 1;
	curr = f->cpu;
	while (!heatmap_is_finished(f, curr, len))
	{
		curr = len;
		len++;
	}
}
