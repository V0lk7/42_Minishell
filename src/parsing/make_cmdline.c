/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:42:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/19 17:35:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/parsing.h"

int	normal_word_lengh(char *str, int i)
{
	int	j;

	j = 0;
	while (str[i + j])
	{
		if (is_character_spe(str[i + j]) || ft_isspace(str[i + j]) == 1)
			break ;
		j++;
	}
	return (j - 1);
}

t_type	*make_lst_minishell(char *str, t_mini *utils)
{
	t_type	*head;
	t_type	*tmp;
	int		i;
	int		count;

	head = NULL;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (head == NULL)
		{
			head = make_node(utils, str, &i, count);
			if (head == NULL)
				return (NULL);
			continue ;
		}
		tmp = make_node(utils, str, &i, count);
		add_back(&head, tmp);
	}
	return (head);
}
