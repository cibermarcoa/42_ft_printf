/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2024/03/22 19:05:57 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_printf_chr(va_arg(args, int));
	else if (c == 's')
		length += ft_printf_str(va_arg(args, char *));
	else if (c == 'p')
		length += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		length += ft_printf_nbr(va_arg(args, int));
	else if (c == 'u')
		length += ft_printf_unbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		length += ft_printf_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		length += ft_printf_chr('%');
	return (length);
}

int	ft_parse(char const *str, va_list args)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += ft_formats(str[i], args);
		}
		else if (str[i - 1] != '%' || str[i - 2] == '%')
			length += ft_printf_chr(str[i]);
		i++;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(str[i + 1], args);
			i++;
		}
		else
			print_length += ft_printf_chr(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
