/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/10 17:21:15 by mdiaz-ca         ###   ########.fr       */
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
		length += ft_printf_ptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		length += ft_printf_nbr(va_arg(args, int));
	else if (c == 'u')
		length += ft_printf_unbr(va_arg(args, int));
	else if (c == 'x')
		length += ft_printf_lhex(va_arg(args, unsigned long));
	else if (c == 'X')
		length += ft_printf_uhex(va_arg(args, unsigned long));
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

int	ft_printf(char const *input, ...)
{
	char	*str;
	int		length;
	va_list	args;

	if (!input || input[0] == '\0')
		return (0);
	str = ft_strdup(input);
	if (!str || str[0] == '\0')
		return (0);
	length = 0;
	va_start(args, input);
	length = ft_parse(str, args);
	va_end(args);
	free(str);
	return (length);
}
