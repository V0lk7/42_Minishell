/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words_splitting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:02:22 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 17:34:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include <stdio.h>

static int	make_expansion(t_expand *cmd, t_mini *mini)
{
	t_expand	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		tmp->word = expansion(mini, tmp->word);
		tmp = tmp->next;
	}
	return (0);
}

static void	display_expand(t_expand *words, char *tmp)
{
	for (int i = 0; tmp[i] != '\0'; i++)
		printf("%i\n", tmp[i]);
	while (words != NULL)
	{
		printf("%i\nstr = %s\n", words->id, words->word);
		words = words->next;
	}
}

int	expansion_wdsplit(char **cmd, t_mini *mini, int *i)
{
	t_expand	*words;
	char		*tmp;

	words = divide_words(cmd[(*i)]);
	if (words == NULL)
		return (1);
	if(make_expansion(words, mini) == 1)
	{
		free_lst_expand(words);
		return (1);
	}
	save_whitespace(words, &tmp);
	display_expand(words, tmp);
	/*if (rebuild_cmd(cmd, i, words) == 1)
	{
		free_lst_expand(words);
		return (1);
	}*/
	free(tmp);
	free_lst_expand(words);
	return (0);
}
