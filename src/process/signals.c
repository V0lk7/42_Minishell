/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:45:47 by jduval            #+#    #+#             */
/*   Updated: 2023/05/02 10:22:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../libft/include/libft.h"
#include <readline/readline.h>
#include <signal.h>

void	n_handler(int signal)
{
	if (signal == SIGINT)
	{
		g_status = 130;
		write(0, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	f_handler(int sig)
{
	if (sig == SIGQUIT)
		g_status = 131;
	if (sig == SIGINT)
		g_status = 130;
}

void	sigint_hdoc(int signal)
{
	if (signal == SIGINT)
		g_status = -130;
}
