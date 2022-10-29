/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:33:18 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/05/14 21:28:44 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define B10 "0123456789"
# define L10 10
# define BU16 "0123456789ABCDEF"
# define BL16 "0123456789abcdef"
# define L16 16

typedef struct s_flag
{
	int	pos;
	int	cnt;
	int	hashtag;
	int	plus;
	int	spce;
}		t_flag;

int		ft_printf(char const *str, ...);
void	ft_do_format(t_flag *flags, char const *str, va_list args);
void	ft_imp_char(t_flag *flags, char c);
void	ft_imp_str(t_flag *flags, char const *cad);
void	ft_imp_m(t_flag *flags, char *base, int bsize, unsigned long long num);
void	ft_imp_nb(t_flag *flags, char *base, int bsize, unsigned long long num);
t_flag	*ft_init_flags(void);
int		ft_is_flag(char c);
void	ft_read_flag(t_flag *flags, char const *str);
void	ft_clear_flags(t_flag *flags);
void	ft_imp_fx(t_flag *flags, char *base, int bsize, unsigned long long n);
void	ft_imp_fxx(t_flag *flags, char *base, int bsize, unsigned long long n);
void	ft_imp_snf(t_flag *flags, char *base, int bsize, int num);
void	ft_imp_nf(t_flag *flags, char *base, int bsize, unsigned long long n);

#endif
