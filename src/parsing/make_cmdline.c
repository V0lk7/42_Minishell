/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:42:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 13:16:01 by jduval           ###   ########.fr       */
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
/*
t_type	*make_node(t_mini *utils, char *str, int *i, int count)
{
	int	k;
	t_type	node;
	t_type	tmp;

	k = *i;
	
}

t_type	*make_ulst_minishell(char *str, t_mini *utils)
{
	t_type	*head;
	t_type	*tmp;
	char	**array;

	head = NULL;
	array = pipe_separation(str);
	if (array == NULL)
		return (NULL);
	while (array[i])
	{
		if (head == NULL)
			head = nodes_creator(array, i, utils);
		tmp = nodes_creator(array, i, utils);
		if (tmp == NULL)
		{
			free_ulst(&head);
			return (NULL);
		}
		add_back(&head, tmp);
		i++;	
	}
	return (head);
}*/
