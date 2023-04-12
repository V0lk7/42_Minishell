/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:21 by jduval            #+#    #+#             */
/*   Updated: 2023/04/12 17:01:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	redirect_expand_setting(t_rdict *red)
{
	if (red->way == HDOC)
	{
		if (ft_strcspn(red->file[0], "\'\"") != ft_strlen(red->file[0]))
			red->expand = 1;
		else
			red->expand = 0;
		if (remove_the_quote(red->file[0]) < 0)
			return (-1);
	}
	else
	{
		if (dollar_in_quote(rdict->file[0]) == TRUE)
			//expansion normal sans wordsplitting; -1 malloc prob, 0 O$K
		else
		{
			//expansion avex wordsplitting
			//-1 = malloc prob, -2 ambiguous redirection, 0 OK
		}
	}
	return (0);
}

static int	command_expand_setting(t_cmd *cmd)
{

}

int	expansion_management(t_data *lst)
{
	while (lst != NULL)
	{
		if (lst->name == REDIRECTION && search_c(lst->data.rdict.file[0]) > -1)
		{
			if (redirect_expand_setting(lst->data.rdict) == -1)
				return (-1);
		}
		else
		{
			if (command_expand_setting(lst->data.cmd) == -1)
				return (-1);
		}
		lst = lst->next;
	}
	return (0);
}
