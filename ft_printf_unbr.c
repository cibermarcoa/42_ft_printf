/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:54:31 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2022/07/13 17:32:25 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_unbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_upnb(nb);
		len += ft_pstr(num);
		free (num);
	}
	return (len);
}

int	ft_pnb(int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb == 0)
		return (write (1, "0", 1));
	num = ft_itoa(nb);
	len = ft_pstr(num);
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
// itoa style 

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

// %u: print unsigned + return length

int	ft_punsignednb(unsigned int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_upnb(nb);
		len += ft_pstr(num);
		free (num);
	}
	return (len);
}

// %d/i: mix function, print nb and return length 

int	ft_pnb(int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb == 0)
		return (write (1, "0", 1));
	num = ft_itoa(nb);
	len = ft_pstr(num);
	free(num);
	return (len);
}