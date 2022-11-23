/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/21 16:36:06 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

e_args ft_toarg(char c)
{
	if ('c')
		return (A_CHAR);
	if ('s')
		return (A_STR);
	if ('p')
		return (A_PT);
	if ('d')
		return (A_DEC);
	if ('i')
		return (A_INT);
	if ('u')
		return (A_UDEC);
	if ('x')
		return (A_HEXLOW);
	if ('X')
		return (A_HEXUP);
	if ('%')
		return (A_PERC);
	return (A_NONE);
}

e_args	ft_argdect(char **s)
{
	
}
