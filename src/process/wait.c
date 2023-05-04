/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:54:03 by jduval            #+#    #+#             */
/*   Updated: 2023/05/03 15:56:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/include/libft.h"

int	wait_function(pid_t pid)
{
	int	wstatus;

	wstatus = 0;
	if (pid == -1)
	{
		while (waitpid(-1, &wstatus, 0) > -1)
			continue ;
		return (0);
	}
	waitpid(pid, &wstatus, 0);
	if (WIFSIGNALED(wstatus) == true)
	{
		if (WTERMSIG(wstatus) == SIGINT)
			ft_printf("\n");
		else if (WTERMSIG(wstatus) == SIGQUIT)
			ft_printf("Quit (core dumped)\n");
	}
	return (WEXITSTATUS(wstatus));
}
