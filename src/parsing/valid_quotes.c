/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:51:19 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 18:00:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../../includes/enum.h"

t_bool	valid_quotes(const char *str)
{
	t_bool	open;
	int		i;
	int		character;

	open = FALSE;
	i = 0;
	character = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i])
	{
		if (open == FALSE && (str[i] == 34 || str[i] == 39))
		{
			character = str[i];
			open = TRUE;
		}
		else if (open == TRUE && str[i] == character)
			open = FALSE;
		i++;
	}
	if (open == TRUE)
		return (FALSE);
	else
		return (TRUE);
}
