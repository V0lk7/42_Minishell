/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:28 by kramjatt          #+#    #+#             */
/*   Updated: 2023/04/25 17:45:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_H
# define CLEAR_H

/*-------Libraries------*/

/*-------Headers------*/
# include "enum.h"
/*--------Structs-------*/

/*--------Free_f-------*/
void	free_exit(t_mini *mini);
/*--------free_lst.c-------*/
void	free_hdoc(t_hdoc *input);
void	free_lst_expand(t_expand *head);
void	free_all_nodes(t_data **head);
/*--------free_in_fork.c-------*/
void	free_all(t_data *lst, t_mini *mini);
#endif
