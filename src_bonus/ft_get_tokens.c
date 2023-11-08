/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:11:30 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 18:55:58 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_flag_attribute(const char *s, char flag, int atoi)
{
	char	*p;
	char	*p_prev;

	p = ft_strchr(s, flag);
	if (!p)
		return (-1);
	if (!atoi)
		return (1);
	if (flag == '0')
	{
		p_prev = ft_strchr(s, '-');
		if (p_prev && p_prev < p)
			return (-1);
		p_prev = ft_strchr(s, '.');
		if (p_prev && p_prev < p)
			return (-1);
	}
	return (ft_atoi(p + 1));
}

t_flags	*ft_get_flags(const char *s)
{
	t_flags	*flags;

	flags = malloc(sizeof(flags));
	if (!flags)
		return (NULL);
	flags->dash = ft_get_flag_attribute(s, '-', 1);
	if (flags->dash != -1)
		flags->zero = -1;
	else
		flags->zero = ft_get_flag_attribute(s, '0', 1);
	flags->dot = ft_get_flag_attribute(s, '.', 1);
	flags->hash = ft_get_flag_attribute(s, '#', 0);
	flags->space = ft_get_flag_attribute(s, ' ', 0);
	flags->plus = ft_get_flag_attribute(s, '+', 1);
	return (flags);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "#05 .02";
// 	t_flags	*f;

// 	f = ft_get_flags(s);
// 	printf("-: %d\n0: %d\n.: %d\n#: %d\ns: %d\n+: %d\n", f->dash, f->zero, f->dot, f->hash, f->space, f->plus);
// 	free (f);
// 	return (0);
// }
