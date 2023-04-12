/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:01:08 by jduval            #+#    #+#             */
/*   Updated: 2023/04/11 14:09:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../include/libft.h"
#include <dirent.h>

int	type_of_file(char *str, int index)
{
	DIR	*directory;
	int	valid;

	valid = access(str, F_OK);
	if (valid == -1)
		return (valid);
	directory = opendir(str);
	if (directory != NULL)
	{
		closedir(directory);
		if (ft_strncmp(str, "./", 2) == 0)
			return (-1);
		return (-2);
	}
	else if (valid == 0 && index == 0 && ft_strncmp(str, "./", 2) != 0)
		return (-1);
	return (valid);
}
