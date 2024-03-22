/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:54:31 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2024/03/22 19:05:32 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pnb(int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb == 0)
		return (write (1, "0", 1));
	num = ft_itoa(nb);
	len = ft_printf_str(num);
	free(num);
	return (len);
}

int	ft_nblen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_upnb(unsigned int nb)
{
	int		len;
	char	*n;

	len = ft_nblen(nb);
	n = malloc(sizeof(char) * (len + 1));
	if (!n)
		return (0);
	n[len] = '\0';
	while (nb)
	{
		n[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (n);
}

int	ft_printf_unbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_upnb(n);
		len += ft_printf_str(num);
		free (num);
	}
	return (len);
}
