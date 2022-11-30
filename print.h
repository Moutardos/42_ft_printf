/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:58:05 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/11/29 11:49:16 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include "args.h"

/* Print the string, if it founds a %, treat it with ft_print_arg and move the
   pointer to the next raw text. Return the number of character printed*/
int	ft_print_group(const char **s, t_arg *arginfo);

/* Print the argument and return the number of character printed */
int   ft_print_arg(t_arg *arginfo);
int   ft_print_arg2(t_arg *arginfo);

int	ft_printf(const char *s, ...);
#endif