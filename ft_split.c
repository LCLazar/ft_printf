/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmilosev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:29:17 by lmilosev          #+#    #+#             */
/*   Updated: 2024/05/14 21:29:19 by lmilosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_array(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

static int	ft_count_words(char const *str, char delim)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] != delim)
		cnt++;
	while (str[i] != '\0')
	{
		if (str[i] == delim && str[i + 1] != delim && str[i + 1] != '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *str, char delim)
{
	char	**splits;
	int		word_number;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	word_number = ft_count_words(str, delim);
	splits = (char **)malloc((word_number + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	while (++i < word_number)
	{
		while (str[j] != '\0' && str[j] == delim)
			j++;
		splits[i] = ft_substr(str, j, ft_word_len(str + j, delim));
		if (!splits[i])
			return (ft_free_array(splits, i));
		splits[i][ft_word_len(str + j, delim)] = '\0';
		j += ft_word_len(str + j, delim);
	}
	splits[i] = NULL;
	return (splits);
}
