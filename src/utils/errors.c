/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:59:08 by jduval            #+#    #+#             */
/*   Updated: 2023/03/28 13:05:30 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	command_not_found(char *cmd)
{
	ft_putstr_fd(2, "😈 Minishell 😈 : Command '");
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, "' not found\n");
}
