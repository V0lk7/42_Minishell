/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_building.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:56:26 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 17:34:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rebuild_cmd(char **cmd, int i, t_expand *words)
{
	char	*str;
	char	**array;

	str = create_str(words);
	if (str == NULL)
		return (NULL);
	array = split_by_str(str, "\n\t ");
	free(str);
	if (array == NULL)
		return (NULL);
}
