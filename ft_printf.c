/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/28 18:04:39 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft/libft.h"

int	ft_print_group(const char **s, t_arg *arginfo)
{
	char	*percent;
	int		char_printed;

	percent = ft_strchr(*s, '%');
	if (percent == NULL)
	{
		ft_putstr_fd((char *) *s, STDOUT);
		char_printed = ft_strlen(*s);
		return (0);
	}
	else
	{
		write(STDOUT, *s, percent - *s);
		char_printed = percent - *s;
		*s += char_printed + 1;
		ft_fill_arg(s, arginfo);
		//char_printed += ft_print_arg()
		char_printed+=1; //enleve
	}
	return (char_printed);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_arg	*arginfo;
	int		size;
	int		char_printed;

	char_printed = 0;
	va_start(ap, s);
	arginfo = malloc(sizeof(t_arg));
	arginfo->ap = &ap;
	size = ft_print_group(&s, arginfo);
	while(size)
	{
		char_printed += size;
		free(arginfo);
		arginfo = malloc(sizeof(t_arg));
		size = ft_print_group(&s, arginfo);
	}
	return (char_printed);
}