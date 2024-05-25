/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmilosev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:30:58 by lmilosev          #+#    #+#             */
/*   Updated: 2024/05/14 21:31:00 by lmilosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (little != NULL && (*little == '\0' || little == big))
		return ((char *)(big));
	if (big != NULL && *big == '\0')
		return (0);
	i = 0;
	while ((size_t)i < len && (size_t)i <= ft_strlen(big) - ft_strlen(little))
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0 \
			&& (size_t)(i + ft_strlen(little)) <= len)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
