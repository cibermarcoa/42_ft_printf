/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2024/03/22 18:24:50 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lhex_len(unsigned	long num)
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

void	ft_put_lhex(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_lhex(num / 16);
		ft_put_lhex(num % 16);
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
/*
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
*/
int	ft_printf_lhex(unsigned long num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_lhex(num);
	return (ft_lhex_len(num));
}
