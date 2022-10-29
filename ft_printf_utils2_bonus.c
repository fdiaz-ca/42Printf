/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:16:31 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/05/14 21:27:58 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_imp_fx(t_flag *flags, char *base, int bsize, unsigned long long n)
{
	if ((flags->hashtag) && (n))
		ft_imp_str(flags, "0x");
	ft_imp_nb(flags, base, bsize, n);
}

void	ft_imp_fxx(t_flag *flags, char *base, int bsize, unsigned long long n)
{
	if ((flags->hashtag) && (n))
		ft_imp_str(flags, "0X");
	ft_imp_nb(flags, base, bsize, n);
}

void	ft_imp_snf(t_flag *flags, char *base, int bsize, int num)
{
	long int	n;

	n = (long int)num;
	if (n < 0)
	{
		ft_imp_char(flags, '-');
		n = n * (-1);
	}
	else if (flags->plus)
		ft_imp_char(flags, '+');
	else if (flags->spce)
		ft_imp_char(flags, ' ');
	ft_imp_nb(flags, base, bsize, n);
}

void	ft_imp_nf(t_flag *flags, char *base, int bsize, unsigned long long n)
{
	if (flags->plus)
		ft_imp_char(flags, '+');
	else if (flags->spce)
		ft_imp_char(flags, ' ');
	ft_imp_nb(flags, base, bsize, n);
}
