/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:43:03 by jduval            #+#    #+#             */
/*   Updated: 2023/05/03 15:46:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../libft/include/libft.h"

int	remove_the_quote(char *str)
{
	char	*tmp;
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = 0;
	flag = 0;
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (tmp == NULL)
		return (-1);
	while (str[++i])
	{
		if (flag == 0 && (str[i] == '\'' || str[i] == '\"'))
			flag = str[i];
		else if (flag > 0 && str[i] == flag)
			flag = 0;
		else if ((flag > 0 && str[i] != flag)
			|| (flag == 0 && (str[i] != '\'' || str[i] != '\"')))
			tmp[j++] = str[i];
	}
	ft_strlcpy(str, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (0);
}

int	quote_removal(t_data *lst)
{
	int	i;

	while (lst != NULL)
	{
		if (lst->name == REDIRECTION)
		{
			if (search_c(lst->data.rdict.file[0], '$') < 0)
				remove_the_quote(lst->data.rdict.file[0]);
		}
		else if (lst->name == COMMAND)
		{
			i = 0;
			while (lst->data.cmd.cmd[i])
			{
				if (search_c(lst->data.cmd.cmd[i], '$') < 0)
					remove_the_quote(lst->data.cmd.cmd[i]);
				i++;
			}
		}
		lst = lst->next;
	}
	return (0);
}
