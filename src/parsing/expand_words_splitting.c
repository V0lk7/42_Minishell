/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words_splitting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:02:22 by jduval            #+#    #+#             */
/*   Updated: 2023/05/01 12:13:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"

static int	make_expansion(t_expand *cmd, t_mini *mini)
{
	t_expand	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (tmp->word[0] == '$' && tmp->word[1] == '\0')
		{	
			tmp = tmp->next;
			continue ;
		}
		tmp->word = expansion(mini, tmp->word, 0);
		tmp = tmp->next;
	}
	return (0);
}

char	**expansion_wdsplit(char **cmd, t_mini *mini, int i)
{
	t_expand	*words;
	char		*tmp;
	int			flag;

	words = divide_words(cmd[i]);
	if (words == NULL)
		return (cmd);
	if (make_expansion(words, mini) == 1)
	{
		free_lst_expand(words);
		return (cmd);
	}
	flag = save_whitespace(words, &tmp);
	cmd = rebuild_cmd(cmd, i, words);
	free_lst_expand(words);
	if (cmd == NULL)
		return (cmd);
	if (flag == 0)
	{
		restore_whitespace(cmd, tmp);
		free(tmp);
	}
	return (cmd);
}
