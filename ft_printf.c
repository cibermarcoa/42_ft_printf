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
