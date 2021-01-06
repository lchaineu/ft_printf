/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:46:00 by lchaineu          #+#    #+#             */
/*   Updated: 2020/12/21 13:39:19 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_tab
{
	va_list		ap;

	char		*input;
	int			len;
	char		act_spec;
	int			width;
	int			precision;
	int			is_precision;
	int			minus;
	int			zero;
	int			negative;
	char		*answer;
	int			is_backslasho;
	int			is_width;

}				t_tab;

int				ft_strcmp(char *s1, char *s2);
int				ft_printf(const char *input, ...);
int				set(t_tab *tab, const char *input);
int				parsing(t_tab *tab);
int				find_spec(t_tab *tab, int i);
int				treat(t_tab *tab, int i);
int				which_spec(t_tab *tab);
void			width_finder(t_tab *tab, int i, int *maxrange);
void			precision_finder(t_tab *tab, int i, int *maxrange);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *str);
int				search_string(char c, char *str);
int				convert_c(t_tab *tab);
char			*ft_itoa_p(unsigned long long int nombre,
							int base, char *charbase);
int				convert_u(t_tab *tab);
int				convert_x(t_tab *tab);
int				convert_big_x(t_tab *tab);
int				convert_d_i(t_tab *tab);
int				convert_p(t_tab *tab);
int				convert_s(t_tab *tab);
char			*strjoin_back(char *s1, char *s2);
char			*strjoin_front(char *s1, char *s2);
char			*addstrfront(t_tab *tab, char c, int len);
char			*addstrback(t_tab *tab, char c, int len);
void			ft_pustr(char *str, t_tab *tab);
void			stars_finder(t_tab *tab, int i, int maxrange);
int				set_again(t_tab *tab);
int				free_malloc_error(void *tofree, int toreturn);
char			*cut_str(char *str, int len);
int				convert_percent(t_tab *tab);
int				convert_u(t_tab *tab);
int				convert_x(t_tab *tab);
int				convert_big_x(t_tab *tab);
int				add_minus(t_tab *tab);
int				display_uxx(t_tab *tab);

#endif
