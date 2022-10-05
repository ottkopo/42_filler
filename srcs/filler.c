/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:16:09 by okoponen          #+#    #+#             */
/*   Updated: 2022/08/23 14:50:27 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	determine_map_size(t_filler *f, char *gnl_ret)
{
	int		i;
	char	x_str[11];
	char	y_str[11];
	int		j;

	i = 0;
	j = 0;
	while (gnl_ret[i] && (gnl_ret[i] < '0' || gnl_ret[i] > '9'))
		i++;
	while (gnl_ret[i] && (gnl_ret[i] >= '0' && gnl_ret[i] <= '9'))
		y_str[j++] = gnl_ret[i++];
	y_str[j] = '\0';
	j = 0;
	i++;
	while (gnl_ret[i] && gnl_ret[i] >= '0' && gnl_ret[i] <= '9')
		x_str[j++] = gnl_ret[i++];
	x_str[j] = '\0';
	f->y = ft_atoi(y_str);
	f->x = ft_atoi(x_str);
	free (gnl_ret);
}

void	create_map(t_filler *f, int x, int y, int i)
{
	char	*gnl_ret;

	f->board = (int **)malloc(sizeof(int *) * (f->y));
	if (!f->board)
		exit (0);
	get_next_line(0, &gnl_ret);
	free (gnl_ret);
	while (y < f->y)
	{
		if (get_next_line(0, &gnl_ret) <= 0)
			exit (0);
		f->board[y] = (int *)malloc(sizeof(int) * (f->x));
		if (!f->board[y])
			exit (0);
		while (gnl_ret[i] != '\0')
		{
			x += check_cell(gnl_ret[i], f, x, y);
			i++;
		}
		i = 0;
		x = 0;
		y++;
		free (gnl_ret);
	}
}

void	determine_piece_size(t_filler *f)
{
	char	*gnl_ret;
	char	x_str[11];
	char	y_str[11];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!get_next_line(0, &gnl_ret))
		return ;
	while (gnl_ret[i] && (gnl_ret[i] > '9' || gnl_ret[i] < '0'))
		i++;
	while (gnl_ret[i] && gnl_ret[i] >= '0' && gnl_ret[i] <= '9')
		y_str[j++] = gnl_ret[i++];
	i++;
	y_str[j] = '\0';
	j = 0;
	while (gnl_ret[i] && gnl_ret[i] >= '0' && gnl_ret[i] <= '9')
		x_str[j++] = gnl_ret[i++];
	x_str[j] = '\0';
	f->piece_x = ft_atoi(x_str);
	f->piece_y = ft_atoi(y_str);
	free (gnl_ret);
}

void	get_piece(t_filler *f)
{
	char	*gnl_ret;
	int		x;
	int		y;

	x = 0;
	y = 0;
	f->piece = (int **)malloc(sizeof(int *) * (f->piece_y));
	while (y < f->piece_y)
	{
		if (!get_next_line(0, &gnl_ret))
			exit (0);
		f->piece[y] = (int *)malloc(sizeof(int) * (f->piece_x));
		while (gnl_ret[x])
		{
			if (gnl_ret[x] == '*')
				f->piece[y][x] = f->player;
			if (gnl_ret[x] == '.')
				f->piece[y][x] = 0;
			x++;
		}
		free (gnl_ret);
		y++;
		x = 0;
	}
}

int	main(void)
{
	t_filler	f;
	char		*gnl_ret;

	get_next_line(0, &gnl_ret);
	if (!gnl_ret[10] || (gnl_ret[10] != '1' && gnl_ret[10] != '2'))
		write(1, "Error: invalid player number\n", 29);
	f.player = gnl_ret[10] - '0';
	f.player = f.player * -1;
	if (f.player == -1)
		f.cpu = -2;
	else
		f.cpu = -1;
	free (gnl_ret);
	while (get_next_line(0, &gnl_ret) > 0)
	{
		determine_map_size(&f, gnl_ret);
		create_map(&f, 0, 0, 0);
		create_heatmap(&f);
		determine_piece_size(&f);
		get_piece(&f);
		if (!place_piece(&f))
			break ;
		free_struct(&f);
	}
	return (0);
}
