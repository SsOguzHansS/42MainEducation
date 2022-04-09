/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogozturk <ogozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:59:55 by ogozturk          #+#    #+#             */
/*   Updated: 2022/04/09 14:59:59 by ogozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		len;

	len = count(n);
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	while (n != 0)
	{
		s[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*s;
	int		len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	s = ft_uitoa(n);
	len = ft_printstr(s);
	free(s);
	return (len);
}
