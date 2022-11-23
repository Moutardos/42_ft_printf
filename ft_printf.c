/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/23 16:07:35 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

t_args ft_toarg(char c)
{
	if (c == 'c')
		return (A_CHAR);
	if (c == 's')
		return (A_STR);
	if (c == 'p')
		return (A_PT);
	if (c == 'd')
		return (A_DEC);
	if (c == 'i')
		return (A_INT);
	if (c == 'u')
		return (A_UDEC);
	if (c == 'x')
		return (A_HEXLOW);
	if (c == 'X')
		return (A_HEXUP);
	if (c == '%')
		return (A_PERC);
	return (A_NONE);
}
/*
t_args	ft_argdect(char **s)
{
	
}*/
