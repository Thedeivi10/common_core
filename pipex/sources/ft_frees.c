/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:40:01 by davigome          #+#    #+#             */
/*   Updated: 2024/12/24 15:26:33 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(t_pipex *pipex)
{
	int	i;

/* 	i = -1;
	while (pipex->pipex[++i])
		free(pipex->pipex[i]);
	i = -1;
	while (pipex->here[++i])
		free(pipex->here[i]); */
	i = -1;
	while (pipex->path[++i])
		free(pipex->path[i]);
//	free(pipex->here);
	free(pipex->path);
//	free(pipex->pipex);
	free(pipex);
}
