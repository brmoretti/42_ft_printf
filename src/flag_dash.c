/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_dash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:25:57 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/30 15:29:07 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_aux.h"

char	*dash_flag(char *str, int dash_len)
{
	int	right_fill;

	right_fill = dash_len - (int)ft_strlen(str);
	while (right_fill-- > 0)
		str = ft_strmerge(str, ft_strdup(" "));
	return (str);
}
