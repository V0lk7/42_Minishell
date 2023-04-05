/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:45:47 by jduval            #+#    #+#             */
/*   Updated: 2023/04/05 13:21:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/enum.h"
#include <signal.h>

void	n_handler(int signal)
{
	if (signal == SIGINT)
	{
		g_status = 130;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
	return ;
}

void	f_handler(int signal)
{
	if (signal == SIGQUIT)
	{
		g_status = 131;
		ft_printf("Quit (core dumped)\n");
	}
	if (signal == SIGINT)
	{
		g_status = 130;
		ft_printf("\n");
	}
}

void	sigint_hdoc(int signal)
{
	if (signal == SIGINT)
		g_status = -130;
}
