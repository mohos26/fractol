/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:48:11 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/29 14:49:03 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

static double	ft_aid(char *s)
{
	int		sing;
	int		aid;
	double	res;

	res = 0;
	sing = 1;
	aid = 0;
	if (*s == 45)
	{
		sing *= -1;
		s++;
	}
	while (*s)
	{
		if (*s == 46 && !aid++)
			s++;
		if (aid)
			res += pow(10, -aid++) * (*s - 48);
		else
			res = res * 10 + *s - 48;
		s++;
	}
	return (res * sing);
}

double	ft_isnumber(char *s, int flag)
{
	int		aid2;
	int		aid;

	aid = 0;
	aid2 = 0;
	if (flag)
		return (ft_aid(s));
	if (!s || !*s)
		return (0);
	if (*s == 45)
		if (!*++s)
			return (0);
	while (*s)
	{
		if (!ft_isdigit(*s) && ((*s == 46 && (aid++ || !aid2)) || *s != 46))
			return (0);
		s++;
		aid2++;
	}
	if (*(s - 1) == 46)
		return (0);
	return (1);
}
