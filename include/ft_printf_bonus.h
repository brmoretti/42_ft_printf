/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:33 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/10 16:13:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	dash;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int		ft_printf(const char *format, ...);

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

char	*ft_itoa_base_int(int n, int base, int upper);
char	*ft_itoa_base_uint(unsigned int n, int base, int upper);
char	*ft_itoa_base_ulong(unsigned long n, int base, int upper);
char	**ft_clear_tab(char **tab);
char	**ft_split_printf(const char *s);
char	ft_last_char(const char *str);
int		ft_putstr_len(const char *s);

int		ft_parse_char(char **token, int c);
int		ft_parse_int(char **token, int n);
int		ft_parse_ptr(char **token, unsigned long ptr);
int		ft_parse_string(char **token, char *str);
int		ft_parse_uint(char **token, unsigned int n, char conversion);

t_flags	*ft_get_flags(const char *s);
int		ft_dash_flag(int prev_len, int target_len);
int		ft_zero_flag_int(unsigned int n, int zeros);
int		ft_zero_flag_uint(char conversion, unsigned int n, int len, int zeros);

#endif
