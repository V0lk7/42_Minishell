/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:28 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/30 18:10:55 by jduval           ###   ########.fr       */
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
void	free_exit(t_mini *mini);
/*--------free_lst.c-------*/
void	free_hdoc(t_hdoc *input);
void	free_all_nodes(t_data **head);
/*--------free_in_fork.c-------*/
void	free_all(t_data *lst, t_mini *mini);
#endif
