/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:46:28 by lchaineu          #+#    #+#             */
/*   Updated: 2020/12/19 14:25:37 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (s1[i] - s2[i]);
		}
	}
	return (s1[i] - s2[i]);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*newstr;
	int		i;
	int		len;

	i = 0;
	if (!(str) || str == 0)
		return (ft_strdup("(null)"));
	else
		len = ft_strlen(str);
	if (!(newstr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[len] = '\0';
	return (newstr);
}

int		search_string(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		free_malloc_error(void *tofree, int toreturn)
{
	free(tofree);
	return (toreturn);
}
