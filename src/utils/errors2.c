/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:19:15 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 14:53:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../libft/include/libft.h"

void	ambiguous_redirection(char *str)
{
	ft_putstr_fd(2, "Minishell : ");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, ": ambiguous redirection\n");
}
