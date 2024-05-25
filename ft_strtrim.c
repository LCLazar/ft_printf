/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmilosev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:32:33 by lmilosev          #+#    #+#             */
/*   Updated: 2024/05/14 21:32:34 by lmilosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checktrim(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*fin;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_checktrim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_checktrim(s1[end - 1], set))
		end--;
	fin = (char *)malloc((end - start + 1) * sizeof(char));
	if (!fin)
		return (NULL);
	ft_strlcpy(fin, s1 + start, end - start + 1);
	return (fin);
}
// ft_checktrim == 0 check instead of ft_checktrim == 1
