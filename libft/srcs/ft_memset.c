/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:51:57 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:01:10 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*destination;
	unsigned char	character;

	destination = (unsigned char *)b;
	character = (unsigned char)c;
	while (len > 0)
	{
		*destination = character;
		destination++;
		len--;
	}
	return (b);
}
