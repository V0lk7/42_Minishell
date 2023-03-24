/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_by_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:43:24 by jduval            #+#    #+#             */
/*   Updated: 2023/03/24 14:19:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	find_rafter(const char *str)
{
	int	i;
	int	quote;
	int	count;

	i = 0;
	quote = 0;
	count = 0;
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote > 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = 0;
		else if (quote == 0 && (str[i] == '>' || str[i] == '<'))
		{
			count++;
			while (str[i] == '<' || str[i] == '>')
				i++;
			continue;
		}
		i++;
	}
	return (count);
}

int	rafter_index(const char *str, int i)
{
	int	quote;

	quote = 0;
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote > 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = 0;
		else if (quote == 0 && (str[i] == '>' || str[i] == '<'))
		{
			while (str[i] == '<' || str[i] == '>' || ft_isspace(str[i]))
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

t_way	rafter_id(const char *str, int i)
{
	int	quote;

	quote = 0;
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote > 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = 0;
		else if (quote == 0 && (str[i] == '>' || str[i] == '<'))
		{
			if (str[i] == '<' && str[i + 1] == '<')
				return (HDOC);
			else if (str[i] == '<' && str[i + 1] != '<')
				return (IN);
			else if (str[i] == '>' && str[i + 1] == '>')
				return (APPEND);
			else
				break ;
		}
		i++;
	}
	return (OUT);
}

int	normal_word_lengh(const char *str, int i)
{
	int	j;
	int	quote;

	quote = 0;
	j = 0;
	while (str[i + j])
	{
		if (quote == 0 && (str[i + j] == '\'' || str[i + j] == '\"'))
			quote = str[i + j];
		else if (quote == 0 && (ft_isspace(str[i + j])
			|| is_character_spe(str[i + j]) == REDIRECTION))
			break ;
		else if (quote > 0 && str[i + j] == quote)
			quote = 0;
		j++;
	}
	return (j - 1);
}
