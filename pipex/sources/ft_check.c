/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:26:09 by davigome          #+#    #+#             */
/*   Updated: 2024/12/25 11:03:01 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_check(char **argv, int argc, t_pipex *pipex, char **envp)
{
	ft_check_narg(argv, argc);
	ft_check_read(argv);
	ft_check_cmds(argv, argc, pipex, envp);
}

void	ft_check_narg(char **argv, int argc)
{
	if (argc < 5)
	{
		ft_printf("Your pipe has not the correct structure\n");
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc",ft_strlen("here_doc")) == 0)
	{
		if (argc < 6)
		{
			ft_printf("Your pipe has not the correct structure\n");
			exit(1);
		}
	}
}

void	ft_check_read(char **argv)
{
	int	fd;

	if (ft_strncmp(argv[1], "here_doc",ft_strlen("here_doc")) != 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Your first file does not exist\n");
			exit(1);
		}
		close(fd);
	}
}

void	ft_check_cmds(char **argv, int argc, t_pipex *pipex, char **envp)
{
	char	*line;
	int		i;
	int		flag;
	int		j;

	j = 2;
	ft_get_path(pipex, envp);
	while(j < argc - 1)
	{
		i = -1;
		flag = 0;
		while(pipex->path[++i])
		{
			line = ft_strjoin(pipex->path[i], "/");
			line = ft_strjoin_g(line, argv[j]);
			if (access(line, X_OK) == 0)
			{
				flag = 1;
				free(line);
				break;
			}
			free(line);
		}
		if (flag == 0)
			break;
		j++;
	}
//	ft_free(pipex);
	if (flag == 0)
	{
		ft_printf("Some command does not exists or works\n");
		exit(1);
	}
}

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->here = NULL;
	pipex->pipex = NULL;
	pipex->path = NULL;
}

void	ft_get_path(t_pipex *pipex, char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")) == 0)
		{
			pipex->path = ft_split(envp[i] + 5, ':');
			break;
		}
		i++;
	}
}