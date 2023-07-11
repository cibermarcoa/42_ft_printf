/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/10 17:21:15 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_itoa_len_ptr(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_ptr(unsigned long n)
{	
	size_t		len;
	char		*str;

	len = ft_itoa_len_ptr(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = 48;
	while (n)
	{
		if ((n % 16) < 10)
			str[len-- - 1] = n % 16 + 48;
		else
			str[len-- - 1] = n % 16 + 87;
		n /= 16;
	}
	return (str);
}

int	ft_printf_ptr(unsigned long p)
{
	char	*str;
	int		length;

	if (p == 0)
		return (ft_printf_str("(nil)"));
	str = ft_itoa_ptr(p);
	length = ft_strlen(str) + 2;
	ft_printf_str("0x");
	ft_printf_str(str);
	free(str);
	return (length);
}
