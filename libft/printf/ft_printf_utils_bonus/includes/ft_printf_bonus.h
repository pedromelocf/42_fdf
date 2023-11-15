/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:51:05 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/10/12 14:00:20 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# define NONCAPHEX "0123456789abcdef"
# define CAPHEX "0123456789ABCDEF"

# include "../../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr_base_bonus(unsigned long int nbr, char *base);
int	ft_putchar_bonus(char c);
int	ft_putstr_bonus(char *str);
int	ft_put_unsigned_bonus(long int nb);
int	ft_put_voidpointer_bonus(char *str);
int	ft_put_hex_bonus(unsigned long int nbr, const char *str, int i);
int	ft_putnbr_hex_bonus(unsigned long int nbr, int index, char *base);
int	ft_putnbr_str_bonus(int nb, const char *str, int i);
int	ft_putnbr_bonus(int nb);
int	ft_check_conversion_bonus(const char *str, int i, va_list args);

#endif
