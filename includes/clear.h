/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:28 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/22 14:02:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_H
# define CLEAR_H

/*-------Libraries------*/

/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"
/*--------Structs-------*/

/*--------Free_f-------*/
void	free_exit(t_mini *mini, t_builts *builts);
/*--------free_lst.c-------*/
void	free_all_nodes(t_data **head);
#endif
