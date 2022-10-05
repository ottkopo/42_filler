/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:24:53 by okoponen          #+#    #+#             */
/*   Updated: 2022/09/19 11:24:54 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*print the final coordinates*/
int	print_final_coords(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	return (1);
}

/*function for creating the initial empty map, converting the input into a matrix, where empty cells are represented
by 0, player 1 pieces are represented by -1 and player 2 pieces are represented by -2*/
int	check_cell(char c, t_filler *f, int x, int y)
{
	if (c == '.')
	{
		f->board[y][x] = 0;
		return (1);
	}
	else if (c == 'o' || c == 'O')
	{
		f->board[y][x] = -1;
		return (1);
	}
	else if (c == 'x' || c == 'X')
	{
		f->board[y][x] = -2;
		return (1);
	}
	return (0);
}
