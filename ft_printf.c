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

static int	ft_formats(char str, va_list args)
{
	int	length;

	length = 0;
	if (str == 'c')
		length += ft_printf_chr(va_arg(args, int));
	else if (str == 's')
	 	length += ft_printf_str(va_arg(args, char *));
	// else if (*str == 'p')
	// 	printf("%d", str + i);
	// else if (*str == 'd')
	// 	printf("%d", str + i);
	// else if (*str == 'i')
	// 	printf("%i", str + i);
	// else if (*str == 'u')
	// 	printf("%u", str + i);
	// else if (*str == 'x')
	// 	printf("%x", str + i);
	// else if (*str == 'X')
	// 	printf("%X", str + i);
	// else if (*str == '%')
	// 	ft_putchar_fd('%', 1);
	return (length);
}

static int	ft_parse(char const *str, va_list args)
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
		else if (str[i - 1] != '%')
			length += ft_printf_char(str[i]);
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
