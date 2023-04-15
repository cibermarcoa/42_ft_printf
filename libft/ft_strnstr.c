/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:53 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/16 19:54:15 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle) || haystack == needle)
		return ((char *)haystack);
	i = 0;
	if (ft_strlen(haystack) > len && ft_strlen(needle) > len)
		return (NULL);
	while (haystack[i] != '\0' && i <= len - ft_strlen(needle))
	{
		if (!ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
