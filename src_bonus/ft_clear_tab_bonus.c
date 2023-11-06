/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:03:50 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 22:19:56 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_clear_tab(char **tab)
{
	char	**ptr;

	ptr = tab;
	while (*ptr)
		free (*ptr++);
	free (tab);
	return (NULL);
}
