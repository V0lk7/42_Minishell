/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:42:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 23:34:39 by jduval           ###   ########.fr       */
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
t_type	*make_args(char *str, t_mini **utils)
{
	t_type	*head;
	t_type	*tmp;

	while (*str)
	{
		
	}
}*/
