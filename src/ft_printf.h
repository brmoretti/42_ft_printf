/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:33 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/01 16:10:30 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

char	*ft_itoa_base_int(int n, int base, int upper);
char	*ft_itoa_base_uint(unsigned int n, int base, int upper);
char	*ft_itoa_base_ulong(unsigned long n, int base, int upper);
void	**ft_clear_tab(void **tab);
char	**ft_split_printf(const char *s);

#endif
