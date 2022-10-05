/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:09:45 by okoponen          #+#    #+#             */
/*   Updated: 2019/11/13 16:13:47 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_iswhitespace(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n') || \
		(c == '\v') || (c == '\r') || (c == '\f'))
		return (1);
	return (0);
}
