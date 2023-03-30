/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:58:52 by jduval            #+#    #+#             */
/*   Updated: 2023/03/30 18:35:18 by jduval           ###   ########.fr       */
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

static int	do_here_doc(t_red *node)
{
	char	*str;
	int		line;
	int		value;

	line = 1;
	while (1)
	{
		str = readline("> ");
		value = hdoc_node_create(node->file, str, &node->input, line);
		if (value == -1)
			return (1);
		else if (value == 1)
			return (0);
		line += ft_strlen(str);
	}
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
				status = do_here_doc(&lst->data.rdict);
		}
		lst = lst->next;
	}
	return (status);
}
