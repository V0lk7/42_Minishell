/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:48:58 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 18:47:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parsing.h"

int	count_words(const char *str, int redirect)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0 && is_character_spe(str[i]) == NONE)
		{
			count++;
			i += normal_word_lengh(str, i);
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return (count - redirect);
}

int	pass_next_word(const char *str, int i)
{
	char	character;

	character = str[i];
	while (str[i] == character)
		i++;
	i = pass_whitespace(str, i);
	while (str[i] && ft_isspace(str[i]) == 0)
		i++;
	return (i - 1);
}

static void	fill_cmdline(char **cmd, const char *str, int *i, int j)
{
	int	len;

	len = normal_word_lengh(str, *i);
	cmd[j] = ft_substr(str, *i, len + 1);
	if (cmd[j] == NULL)
	{
		*i = -1;
		if (j > 0)
			free_array2d(cmd);
		return ;
	}
	*i = *i + len;
}

char	**fill_array_cmd(const char *str, int words)
{
	char	**cmd;
	int		i;
	
	cmd = malloc(sizeof(char *) * (words + 1));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	words = 0;
	while (str[i])
	{
		if (is_character_spe(str[i]) == REDIRECTION)
			i = pass_next_word(str, i);
		else if (ft_isspace(str[i]) == 0 && is_character_spe(str[i]) == NONE)
		{
			fill_cmdline(cmd, str, &i, words);
			if (i < 0)
				return (NULL);
			words++;
		}
		i++;
	}
	cmd[words] = NULL;
	return (cmd);
}
