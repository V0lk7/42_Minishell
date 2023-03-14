/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:14:34 by jduval            #+#    #+#             */
/*   Updated: 2023/03/14 17:15:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_bool	first_character(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (FALSE);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (FALSE);
	if (str[i] == '|')
		return (FALSE);
	else
		return (TRUE);
}

int	valid_special_character(char *str, int i)
{
	int	c;

	c = *str;
	if (c == '|' && str[i + 1] == c)
		return (index * (-1));

}

int	syntax_is_valid(const char *str)
{
	int	len;
	int	pipe;

	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == '|')
		{
			i = valid_special_character(str + i, i);
			if (i < 0)
				return (i);
			i = 
		}
		
	}
}
