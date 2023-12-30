/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:45:19 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 15:29:13 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

char	*len_flag(char *str, int len_flag)
{
	int		left_fill;

	left_fill = len_flag - (int)ft_strlen(str);
	while (left_fill-- > 0)
		str = ft_strmerge(ft_strdup(" "), str);
	return (str);
}
