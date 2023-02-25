/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 20:29:38 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	prompt(void)
{
	char	*line;

	while (1)
	{
		line = readline("Minishell de Keny et Jean > ");
		history(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	status;

	prompt();
	return (status);
}
