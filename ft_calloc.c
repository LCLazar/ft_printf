/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmilosev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:29:00 by lmilosev          #+#    #+#             */
/*   Updated: 2024/05/14 21:29:02 by lmilosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	bytes;

	if (!nmemb || !size)
		return (malloc(0));
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	bytes = nmemb * size;
	array = (void *)malloc(bytes);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, bytes);
	return (array);
}
