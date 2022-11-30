/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:12:51 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/30 10:49:03 by lcozdenm         ###   ########.fr       */
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
		*s = NULL;
	}
	else
	{
		write(STDOUT, *s, percent - *s);
		char_printed = percent - *s;
		*s += char_printed + 1;
		ft_fill_arg(s, arginfo);
		char_printed += ft_print_arg(arginfo);
	}
	return (char_printed);
}


/* PROTEGER LES MALLOCS */
int ft_print_arg(t_arg *arginfo)
{
	char	*res;
	char	*res_2;
	int		wc;

	wc = 0;
	if (arginfo->ctype == A_DEC || arginfo->ctype == A_INT)
		wc = ft_putnbr_fd(va_arg(*(arginfo->ap), int), STDOUT);
	else if (arginfo->ctype == A_CHAR)
		wc = ft_putchar_fd((unsigned char) va_arg(*(arginfo->ap), int), STDOUT);
	else if (arginfo->ctype == A_STR)
		wc = ft_putstr_fd(va_arg(*(arginfo->ap), char *), STDOUT);
	else if (arginfo->ctype == A_HEXLOW || arginfo->ctype == A_HEXUP)
	{
		res = ft_itohexa(va_arg(*(arginfo->ap), int));
		if (arginfo->ctype == A_HEXLOW)
			wc = ft_putstr_fd(res, STDOUT);
		if (arginfo->ctype == A_HEXUP)
		{
			res_2 = ft_strup(res);
			wc = ft_putstr_fd(res_2, STDOUT);
			free(res_2);
		}
		free(res);
	}
	else
		return (ft_print_arg2(arginfo));
	return (wc);
}


int ft_print_arg2(t_arg *arginfo)
{
	int 	wc;

	wc = 0;
	if (arginfo->ctype == A_PERC)
		wc = ft_putchar_fd('%', STDOUT);
	else if (arginfo->ctype == A_UDEC)
	{
		wc = ft_putnbr_fd(va_arg(*(arginfo->ap), unsigned int), STDOUT);
	}
	else if (arginfo->ctype == A_PT)
	{
		wc += ft_putstr_fd("0x", STDOUT);
		wc += ft_puthex_fd((size_t) va_arg(*(arginfo->ap), void *), STDOUT);
	}
	return (wc);
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
	char_printed += size;
	while (s != NULL)
	{
		free(arginfo);
		arginfo = malloc(sizeof(t_arg));
		arginfo->ap = &ap;
		size = ft_print_group(&s, arginfo);
		char_printed += size;
	}
	free(arginfo);
	va_end(ap);
	return (char_printed);
}
