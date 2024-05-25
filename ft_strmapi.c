/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmilosev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:29:29 by lmilosev          #+#    #+#             */
/*   Updated: 2024/05/14 21:29:30 by lmilosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*fin;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	fin = malloc(len * sizeof(char) + 1);
	if (!fin)
		return (NULL);
	i = 0;
	while (i < len)
	{
		fin[i] = (*f)(i, s[i]);
		i++;
	}
	fin[i] = '\0';
	return (fin);
}
