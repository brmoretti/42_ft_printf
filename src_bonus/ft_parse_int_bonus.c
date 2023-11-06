/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 16:52:20 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_parse_int(char **token, int n)
{
	free(*token);
	*token = ft_itoa_base_int(n, 10, 0);
	if (!*token)
		return (NULL);
	return (*token);
}
