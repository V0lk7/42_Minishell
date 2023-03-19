/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:14:38 by jduval            #+#    #+#             */
/*   Updated: 2023/03/19 17:17:44 by jduval           ###   ########.fr       */
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
t_type	*new_noide(t_class name, t_red *redirect, t_cmd *command);
void	add_back_unode(t_type **head, t_type *node);
t_type	*reach_last_node(t_type *head);
int		count_cmd(t_type *head);

#endif
