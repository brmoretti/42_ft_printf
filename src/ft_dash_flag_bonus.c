/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:25:57 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/15 12:46:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dash_flag(int prev_len, int target_len)
{
	int	right_fill;
	int	i;

	right_fill = target_len - prev_len;
	if (right_fill <= 0)
		return (0);
	i = 0;
	while (i++ < right_fill)
		write(1, " ", 1);
	return (right_fill);
}
