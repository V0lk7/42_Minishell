/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:34:52 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/10 16:27:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
//# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include "../src/libft/include/libft.h"

typedef struct s_builts
{
	char	*str;

}	t_builts;

typedef struct s_minis
{	
	char		**cmd;
	char		**envp_cpy;
	t_builts	*b_ptr;

}	t_minis;

void	history(char *argv);

/*-----BuiltIN_f-----*/
void	ft_echo(t_minis *minis);
void	ft_env(t_minis *minis);
void	ft_pwd(t_minis *minis);
void	ft_unset(t_minis *minis);
void	is_built(t_minis *minis);

/*-----Init_f-----*/
void	init_builts(t_builts *builts);
void	init_minishell(t_minis *minis, t_builts *builts, char **envp);

#endif
