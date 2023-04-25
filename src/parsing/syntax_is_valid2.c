/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_is_valid2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:09:23 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:56:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	first_character(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (-2147483647);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (-2147483647);
	if (str[i] == '|')
		return (i * (-1));
	else
		return (i);
}

t_spe	is_character_spe(int c)
{
	if (c == '<' || c == '>')
		return (REDIRECTION);
	else if (c == '|')
		return (PIPE);
	else
		return (NONE);
}

int	pass_whitespace(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j] && ft_isspace(str[i + j]))
		j++;
	return (i + j);
}

int	valid_redirection(const char *str, int i, char character)
{
	t_spe	flag;

	if (i + 2 <= (int)ft_strlen(str))
		flag = is_character_spe(str[i + 2]);
	else
		flag = NONE;
	if (str[i + 1] == '\0')
		return ((i) * -1);
	if (str[i + 1] == character && flag == NONE)
		return (i + 2);
	else if (str[i + 1] != character
		&& is_character_spe(str[i + 1]) == REDIRECTION)
		return (i + 2);
	else if (str[i + 1] != character && is_character_spe(str[i + 1]) == NONE)
		return (i + 1);
	else if (str[i +1] != character && str[i + 1] == '|')
		return ((i + 1) * (-1));
	else
		return (i * (-1));
}
