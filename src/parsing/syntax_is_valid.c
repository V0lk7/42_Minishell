/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:14:34 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 16:43:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/enum.h"

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

	tmp = i - 1;
	if (ft_isspace(str[i]))
		i = pass_whitespace(str, i);
	if (str[i] == '\0')
		return (tmp * (-1));
	else if (str[i] == '|')
		return (i * (-1));
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

static int	change_under_quote(char c, int under_quote)
{
	if (under_quote == 0 && (c == '\'' || c == '\"'))
		return (c);
	else if (under_quote > 0 && c == under_quote)
		return (0);
	else
		return (under_quote);
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
		under_quote = change_under_quote(str[i], under_quote);
		if (under_quote == 0)
		{
			character = is_character_spe(str[i]);
			if (character == PIPE || character == REDIRECTION)
			{
				i = past_character(str, i, character);
				if (i <= 0)
					return (i);
				continue ;
			}
		}
		i++;
	}
	return (i);
}
