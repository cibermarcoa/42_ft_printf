/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/10 17:21:15 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_itoa(int n);

int			ft_printf(char const *input, ...);
int			ft_parse(char const *str, va_list args);
int			ft_formats(char c, va_list args);

int			ft_printf_chr(int c);
int			ft_printf_str(char *str);
int			ft_printf_nbr(int nb);
int			ft_printf_unbr(int nb);
int			ft_printf_ptr(unsigned long p);
int			ft_printf_lhex(unsigned long hex);
char		*ft_itoa_lhex(unsigned long n);
size_t		ft_itoa_len_lhex(unsigned long n);
int			ft_printf_uhex(unsigned long hex);

#endif
