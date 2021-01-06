/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:26 by lchaineu          #+#    #+#             */
/*   Updated: 2020/12/21 12:28:45 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		d_precision(t_tab *tab)
{
	if (!(tab->answer = addstrfront(tab, '0', tab->precision)))
		return (-1);
	if (tab->negative && tab->answer[0] != '-')
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	return (1);
}

static	int		d_width(t_tab *tab)
{
	if (tab->minus)
	{
		if (tab->negative && !(search_string('-', tab->answer)))
			tab->width--;
		if (!(tab->answer = addstrback(tab, ' ', tab->width)))
			return (-1);
	}
	else
	{
		if (tab->zero && !(tab->precision))
		{
			if (!(tab->answer = addstrfront(tab, '0', tab->width)))
				return (-1);
			if (tab->negative && tab->answer[0] != '-')
				tab->answer[0] = '-';
		}
		else
		{
			if (!(tab->answer = addstrfront(tab, ' ', tab->width)))
				return (-1);
		}
	}
	if (add_minus(tab) == -1)
		return (-1);
	return (1);
}

static	int		display_d(t_tab *tab)
{
	if (tab->precision)
		if (d_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (d_width(tab) == -1)
			return (-1);
	return (1);
}

int				convert_d_i(t_tab *tab)
{
	char			*str;
	long int		num;

	num = va_arg(tab->ap, int);
	if (num < 0)
	{
		num = -num;
		tab->negative = 1;
	}
	if (!(str = ft_itoa_p(num, 10, "0123456789")))
		return (-1);
	if (!(tab->answer = strjoin_back(tab->answer, str)))
		free_malloc_error(str, -1);
	free(str);
	if (((tab->negative && !(tab->is_precision)) ||
	(tab->negative && tab->is_precision && (!tab->precision)))
	&& !(tab->width && tab->zero && ft_strlen(tab->answer) < tab->width))
	{
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	}
	if (tab->is_precision == 1 && tab->precision == 0 && tab->answer[0] == '0')
		tab->answer[0] = '\0';
	return (display_d(tab));
}

int				add_minus(t_tab *tab)
{
	if (tab->negative && !(search_string('-', tab->answer)))
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	return (1);
}
