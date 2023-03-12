#ifndef BUILT_IN_H
# define BUILT_IN_H

/*-------Libraries------*/
# include <limits.h>
# include <stdio.h>
/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"

/*-----Built_IN_f-----*/
void	ft_echo(t_mini *mini);
void	ft_env(t_mini *mini);
void	ft_exit(t_mini *mini);
void	ft_pwd(t_mini *mini);
void	ft_unset(t_mini *mini);
void	is_built(t_mini *mini);

/*-----Init_f-----*/
void	init_builts(t_builts *builts);

#endif
