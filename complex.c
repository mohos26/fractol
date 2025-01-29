/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:49:22 by mhoussas          #+#    #+#             */
/*   Updated: 2025/01/29 18:00:28 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_complex	ft_pow2(t_complex x)
{
	t_complex	result;

	result.real = x.real * x.real - x.img * x.img;
	result.img = 2 * x.real * x.img;
	return (result);
}

t_complex	ft_add(t_complex x, t_complex y)
{
	t_complex	result;

	result.real = x.real + y.real;
	result.img = x.img + y.img;
	return (result);
}
