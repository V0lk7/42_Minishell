/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:18:20 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/02 19:36:59 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <readline/history.h>

void	history(char *argv)
{
	if (ft_strncmp(argv, "", ft_strlen(argv)))
		add_history(argv);
}
