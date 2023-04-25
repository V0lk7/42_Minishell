/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:31:19 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 14:14:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../../includes/utils.h"
#include "../../includes/clear.h"

int	dollar_end(const char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '$')
			return (i);
		i++;
	}
	return (i);
}

int	next_expand_word(const char *str, int i)
{
	int	quote;

	quote = 0;
	if (i - 1 >= 0 && str[i - 1] == '$')
		return (dollar_end(str, i));
	if (i - 1 >= 0 && (str[i - 1] == '\'' || str[i - 1] == '\"'))
		quote = str[i - 1];
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote > 0 && str[i] == quote)
			quote = 0;
		else if (quote == 0 && str[i] == '$')
			return (i);
		i++;
	}
	return (i);
}

int	id_word(const char *str, int start)
{
	if (str[start] != '$')
		return (0);
	return (1);
}

t_expand	*node_expand(const char *cmd, int *i)
{
	int			start;
	char		*str;
	int			id;
	t_expand	*node;

	start = *i;
	*i = next_expand_word(cmd, *i + 1);
	id = id_word(cmd, start);
	str = ft_substr(cmd, start, (*i - start));
	if (str == NULL)
		return (NULL);
	node = new_node_expand(str, id);
	if (node == NULL)
		free(str);
	return (node);
}

t_expand	*divide_words(const char *cmd)
{
	t_expand	*tmp;
	t_expand	*head;
	int			i;

	i = 0;
	head = node_expand(cmd, &i);
	if (head == NULL)
		return (NULL);
	while (cmd[i])
	{
		tmp = node_expand(cmd, &i);
		if (tmp == NULL)
		{
			free_lst_expand(head);
			return (NULL);
		}
		add_back_expand(&head, tmp);
	}
	return (head);
}
