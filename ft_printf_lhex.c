/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:32 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2024/03/22 19:04:35 by mdiaz-ca         ###   ########.fr       */
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

int	ft_printf_lhex(unsigned long num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_lhex(num);
	return (ft_lhex_len(num));
}
