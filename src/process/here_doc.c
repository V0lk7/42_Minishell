/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:58:52 by jduval            #+#    #+#             */
/*   Updated: 2023/04/05 13:28:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/utils.h"

static int	hdoc_node_create(char *limits, char *str, t_hdoc **head, int line)
{
	int		flag;
	size_t	len;
	t_hdoc	*node;

	len = ft_strlen(limits);
	flag = 0;
	if (str == NULL
		|| (ft_strncmp(str, limits, len) == 0 && len == ft_strlen(str)))
	{
		flag = 1;
		if (str == NULL)
			ctrl_d_hdoc(limits, line);
		str = ft_calloc(1, sizeof(char));
		if (str == NULL)
			return (-1);
	}
	node = create_hdoc_node(str, flag);
	if (node == NULL)
		return (-1);
	add_back_hdoc(head, node);
	return (flag);
}

int	hdoc_rl_event_hook(void)
{
	if (g_status == -130)
		rl_done = 1;
	return (0);
}

static int	do_here_doc(t_red *node)
{
	char	*str;
	int		line;
	int		value;

	rl_event_hook = hdoc_rl_event_hook;
	signal(SIGINT, sigint_hdoc);
	line = 1;
	while (1)
	{
		str = readline("> ");
		if (g_status == -130)
		{
			if (str != NULL)
				free(str);
			free_hdoc(node->input);
			return (-1);
		}
		value = hdoc_node_create(node->file, str, &node->input, line);
		if (value == -1)
			return (1);
		else if (value == 1)
			return (0);
		line += ft_strlen(str);
	}
	return (0);
}

static int	put_hdoc_in_file(t_red *red)
{
	t_hdoc	*tmp;

	if (create_tmp_hdoc(red) == -1)
		return (-1);
	tmp = red->input;
	while (tmp)
	{
		ft_putstr_fd(red->w_fd, tmp->line);
		if (tmp->last == 1)
			ft_putstr_fd(red->w_fd, "\0");
		else
			ft_putstr_fd(red->w_fd, "\n");
		tmp = tmp->next;
	}
	close (red->w_fd);
	return (0);
}

int	here_doc(t_data *lst)
{
	int	status;

	status = 0;
	while (lst && status == 0)
	{
		if (lst->name == REDIRECTION)
		{
			if (lst->data.rdict.way == HDOC)
			{
				status = do_here_doc(&lst->data.rdict);
				if (status == -1)
					return (-1);
				if (put_hdoc_in_file(&lst->data.rdict) == -1)
					return (-1);
			}
		}
		lst = lst->next;
	}
	return (status);
}
