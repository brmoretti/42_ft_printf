/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:50:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:30 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_parse_string(char **token, char *str)
{
	free (*token);
	if (!str)
		return (ft_putstr_len("(null)"));
	return (ft_putstr_len(str));
}
