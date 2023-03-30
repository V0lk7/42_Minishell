/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:01:08 by jduval            #+#    #+#             */
/*   Updated: 2023/03/30 18:37:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <dirent.h>

int	type_of_file(char *str)
{
	DIR	*directory;
	int	valid;

	valid = access(str, F_OK);
	if (valid == -1)
		return (valid);
	directory = opendir(str);
	if (directory == NULL)
		return (0);
	closedir(directory);
	return (-2);
}
