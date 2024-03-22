/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2024/03/22 18:26:10 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
size_t	ft_itoa_len_uhex(unsigned long n)
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

char	*ft_itoa_uhex(unsigned long n)
{	
	size_t		len;
	char		*str;

	len = ft_itoa_len_uhex(n);
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
			str[len-- - 1] = n % 16 + 55;
		n /= 16;
	}
	return (str);
}

int	ft_printf_uhex(unsigned long hex)
{
	char	*str;
	int		length;

	str = ft_itoa_uhex(hex);
	length = ft_strlen(str);
	ft_printf_str(str);
	free(str);
	return (length);
}
*/






int	ft_uhex_len(unsigned	long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_uhex(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_uhex(num / 16);
		ft_put_uhex(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
				ft_putchar_fd((num - 10 + 'a'), 1);
		}
	}
}

int	ft_printf_uhex(unsigned long num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_uhex(num);
	return (ft_uhex_len(num));
}