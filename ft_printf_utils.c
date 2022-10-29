/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:26:05 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/05/14 12:44:21 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_imp_char(int *cnt, char c)
{
	write(1, &c, 1);
	*cnt += 1;
}

void	ft_imp_str(int *cnt, char *cad)
{
	int	i;

	if (!cad)
		ft_imp_str(cnt, "(null)");
	else
	{
		i = 0;
		while (cad[i])
			ft_imp_char(cnt, cad[i++]);
	}
}

void	ft_imp_nb(int *cnt, char *base, int bsize, unsigned long long num)
{
	if (num >= (unsigned long long)bsize)
	{
		ft_imp_nb(cnt, base, bsize, (num / bsize));
		ft_imp_char(cnt, base[num % bsize]);
	}
	else
		ft_imp_char(cnt, base[num]);
}

void	ft_imp_snb(int *cnt, char *base, int bsize, int num)
{
	long int	n;

	n = (long int)num;
	if (n < 0)
	{
		ft_imp_char(cnt, '-');
		n = n * (-1);
	}
	ft_imp_nb(cnt, base, bsize, n);
}

void	ft_imp_mem(int *cnt, char *base, int bsize, unsigned long long num)
{
	write(1, "0x", 2);
	*cnt += 2;
	ft_imp_nb(cnt, base, bsize, num);
}
