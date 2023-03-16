/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:14:34 by jduval            #+#    #+#             */
/*   Updated: 2023/03/16 13:43:54 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/enum.h"

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
	int j;

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
	if (str[i + 1] == character && flag == NONE)
		return (i + 2);
	else if (str[i + 1] != character
		&& is_character_spe(str[i + 1]) == REDIRECTION)
		return (i + 2);
	else if (str[i + 1] != character && is_character_spe(str[i + 1]) == NONE)
		return (i + 1);
	else
		return (i * (-1));
}

int	redirection_case(const char *str, int i)
{
	int	character;
	int	tmp;

	tmp = i;
	character = str[i];
	i = valid_redirection(str, i, character);
	if (i < 0)
		return (i);
	i = pass_whitespace(str, i);
	if (str[i] == '\0' || str[i] == '|' || is_character_spe(str[i]) != NONE)
		return (tmp * (-1));
	else
		return (i);
}

int	pipe_case(const char *str, int i)
{
	int	tmp;

	tmp = i;
	if (ft_isspace(str[i]))
		i = pass_whitespace(str, i);
	if (str[i] == '\0' || str[i] == '|')
		return (tmp * (-1));
	else if (str[i] == '<' || str[i] == '>')
	{
		i = redirection_case(str, i);
		if (i < 0)
			return (i * (-1));
		else
			return (i);
	}
	return (i);
}

int	past_character(const char *str, int i, t_spe character)
{
	if (character == PIPE)
		i = pipe_case(str, i + 1);
	else
		i = redirection_case(str, i);
	return (i);	
}

int	is_syntax_valid(const char *str)
{
	int		i;
	int		under_quote;
	t_spe	character;

	i = 0;
	character = NONE;
	under_quote = 0;
	while (str[i])
	{
		if (under_quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			under_quote = str[i];
		else if (under_quote > 0 && str[i] == under_quote)
			under_quote = 0;
		if (under_quote == 0)
		{
			character = is_character_spe(str[i]);
			if (character == PIPE || character == REDIRECTION)
			{
				i = past_character(str, i, character);
				if (i < 0)
					return (i);
				continue ;
			}
		}
		i++;
	}
	return (i);
}
