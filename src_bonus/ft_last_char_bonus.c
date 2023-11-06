/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:16:02 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 16:38:55 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_last_char(char *str)
{
	while (*str && *(str + 1))
		str++;
	return (*str);
}
