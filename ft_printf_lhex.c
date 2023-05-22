/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2022/04/10 17:21:15 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lhex(unsigned long hex)
{
	char	*str;
	int		length;

	str = ft_itoa_lhex(hex);
	length = ft_strlen(str);
	ft_printf_str(str);
	free(str);
	return (length);
}

char	*ft_itoa_lhex(unsigned long n)
{	
	size_t		len;
	char		*str;

	len = ft_itoa_len_lhex(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = 48;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		if ((n % 16) >= 0 && ((n % 16) < 10))
			str[len-- - 1] = n % 16 + 48;
		else
			str[len-- - 1] = n % 16 + 87;
		n /= 16;
	}
	return (str);
}

size_t	ft_itoa_len_lhex(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}
