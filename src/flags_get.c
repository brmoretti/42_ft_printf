/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:11:30 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:29:29 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

static int	get_flag_attribute(const char *s, char flag, int atoi)
{
	char	*p;

	p = ft_strchr(s, flag);
	if (!p)
		return (-1);
	if (!atoi)
		return (1);
	while (*p == flag)
		p++;
	return (ft_atoi(p));
}

static int	determine_start_place(const char *s)
{
	char	conversion;
	int		move;

	conversion = ft_last_char(s);
	move = 1;
	if (conversion == 's' || conversion == 'c')
	{
		while (*(++s) == ' ')
			move++;
	}
	return (move);
}

t_flags	*get_flags(const char *s)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	if (ft_isdigit(*(s + determine_start_place(s))))
		flags->len = ft_atoi(s + 1);
	else
		flags->len = -1;
	flags->dash = get_flag_attribute(s, '-', 1);
	flags->dot = get_flag_attribute(s, '.', 1);
	if (flags->dash != -1 || flags->dot != -1)
		flags->zero = -1;
	else
		flags->zero = get_flag_attribute(s, '0', 1);
	flags->hash = get_flag_attribute(s, '#', 0);
	flags->plus = get_flag_attribute(s, '+', 0);
	if (flags->plus != -1)
		flags->space = -1;
	else
		flags->space = get_flag_attribute(s, ' ', 0);
	return (flags);
}
