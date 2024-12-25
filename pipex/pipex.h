/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:21:12 by davigome          #+#    #+#             */
/*   Updated: 2024/12/24 14:41:52 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	**here;
	int		**pipex;
	char	**path;	
}		t_pipex;

// FT_CHECK.C //
void	ft_check(char **argv, int argc, t_pipex *pipex, char **envp);
void	ft_check_narg(char **argv, int argc);
void	ft_check_read(char **argv);
void	ft_check_cmds(char **argv, int argc, t_pipex *pipex, char **envp);
void	ft_init_pipex(t_pipex *pipex);
void	ft_get_path(t_pipex *pipex, char **envp);

// FT_FREES.C //
void	ft_free(t_pipex *pipex);

#endif