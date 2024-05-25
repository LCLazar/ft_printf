/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmilosev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:32:56 by lmilosev          #+#    #+#             */
/*   Updated: 2024/05/14 21:32:57 by lmilosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	lens;
	size_t	lend;
	size_t	copylen;

	lens = ft_strlen(src);
	lend = ft_strlen(dest);
	if (lend >= destsize)
		lend = destsize;
	if (destsize <= lend)
		return (destsize + lens);
	copylen = destsize - lend - 1;
	if (copylen > lens)
		copylen = lens;
	ft_memcpy(dest + lend, src, copylen);
	dest[lend + copylen] = '\0';
	return (lend + lens);
}
