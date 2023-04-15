/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiaz-ca <mdiaz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:53 by mdiaz-ca          #+#    #+#             */
/*   Updated: 2023/03/31 18:10:52 by mdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_end(char const *s, char c)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			end++;
		}
	}
	return (end);
}

static char	**ft_freemem(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	return (NULL);
}

static char	*ft_cpy(char *word, size_t len,
					char const *s, int start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_word_malloc(char **str,
				size_t end, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;

	j = 0;
	i = 0;
	len = 0;
	while (s[i] && j < end)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i++] != c)
			len++;
		str[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (str[j] == 0)
			return (ft_freemem(str));
		ft_cpy(str[j], len, s, start);
		len = 0;
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	end;
	char	**str;

	if (s == NULL)
		return (NULL);
	end = ft_end(s, c);
	str = (char **)malloc(sizeof(char *) * (end + 1));
	if (!str)
		return (NULL);
	str[end] = NULL;
	ft_word_malloc(str, end, s, c);
	return (str);
}
