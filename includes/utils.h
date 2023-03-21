/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:14:38 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 17:45:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*-------Libraries------*/

/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"
/*--------Structs-------*/

/*--------list_utils.c-------*/
void	add_back_unode(t_type **head, t_type *node);
int		count_cmd(t_type *head);
t_type	*new_noide(t_class name, t_red *redirect, t_cmd *command);
t_type	*reach_last_node(t_type *head);
/*--------split_by_pipe_utils.c-------*/
int		*find_index_pipe(char *str);

/*--------$-------*/
void	dollars(t_mini *mini);
#endif
