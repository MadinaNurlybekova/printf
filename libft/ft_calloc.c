/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhadan <vzhadan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:02:18 by vzhadan           #+#    #+#             */
/*   Updated: 2023/02/09 15:12:40 by vzhadan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Allocates the requested memory and returns a pointer to it.
 *	Sets allocated memory to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb * size / nmemb < size)	
		return (NULL);
	p = (char *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return ((void *)p);
}
