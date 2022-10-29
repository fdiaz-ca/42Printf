/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:09:58 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/05/14 21:27:02 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag	*ft_init_flags(void)
{
	t_flag	*tmp;

	tmp = (t_flag *)malloc(sizeof(t_flag));
	if (!tmp)
		return (NULL);
	tmp->pos = 0;
	tmp->cnt = 0;
	tmp->hashtag = 0;
	tmp->plus = 0;
	tmp->spce = 0;
	return (tmp);
}

int	ft_is_flag(char c)
{
	if ((c == '#') || (c == '+') || (c == ' '))
		return (1);
	return (0);
}

void	ft_read_flag(t_flag *flags, char const *str)
{
	while (ft_is_flag(str[flags->pos]))
	{
		if (str[flags->pos] == '#')
			flags->hashtag = 1;
		if (str[flags->pos] == '+')
			flags->plus = 1;
		if (str[flags->pos] == ' ')
			flags->spce = 1;
		flags->pos += 1;
	}
}

void	ft_do_format(t_flag *flags, char const *str, va_list args)
{
	if ((str[flags->pos] == 'd') || (str[flags->pos] == 'i'))
		ft_imp_snf(flags, B10, L10, va_arg(args, int));
	if (str[flags->pos] == 'u')
		ft_imp_nf(flags, B10, L10, va_arg(args, unsigned int));
	if (str[flags->pos] == 'c')
		ft_imp_char(flags, va_arg(args, int));
	if (str[flags->pos] == '%')
		ft_imp_char(flags, '%');
	if (str[flags->pos] == 's')
		ft_imp_str(flags, va_arg(args, char *));
	if (str[flags->pos] == 'x')
		ft_imp_fx(flags, BL16, L16, va_arg(args, unsigned int));
	if (str[flags->pos] == 'X')
		ft_imp_fxx(flags, BU16, L16, va_arg(args, unsigned int));
	if (str[flags->pos] == 'p')
		ft_imp_m(flags, BL16, L16, va_arg(args, unsigned long long));
}

int	ft_printf(char const *str, ...)
{
	int		count;
	t_flag	*flags;
	va_list	args;

	va_start(args, str);
	flags = ft_init_flags();
	if (!flags)
		return (-1);
	while (str[flags->pos])
	{
		if (str[flags->pos] == '%')
		{
			flags->pos += 1;
			ft_read_flag(flags, str);
			ft_do_format(flags, str, args);
			ft_clear_flags(flags);
		}
		else
			ft_imp_char(flags, str[flags->pos]);
		flags->pos += 1;
	}
	va_end(args);
	count = flags->cnt;
	free(flags);
	return (count);
}
