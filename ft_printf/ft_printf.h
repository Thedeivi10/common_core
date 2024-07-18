/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:58:58 by davigome          #+#    #+#             */
/*   Updated: 2024/06/30 23:04:26 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT

# include <unistd.h>
# include <stdarg.h>
# include "/home/losbichos/Common_Core/libft/libft.h"

int	ft_printf(const char *format, ...);

#endif