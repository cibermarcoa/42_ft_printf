/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2024/03/22 17:56:43 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_ptr_len(uintptr_t num)
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

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

/*
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

int	ft_printf_ptr(unsigned long long p)
{
	char	*str;
	int		length;

	if (p == 0)
		return (ft_printf_str("0"));
	str = ft_itoa_ptr(p);
	length = ft_strlen(str) + 2;
	ft_printf_str("0x");
	ft_printf_str(str);
	free(str);
	return (length);
}
*/