/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:34:35 by davigome          #+#    #+#             */
/*   Updated: 2024/12/24 13:37:06 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/* void	ft_init(char **argv, int argc)
{
	
} */

int main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	
	pipex = malloc(sizeof(t_pipex));
    if (!pipex)
    {
        perror("Error allocating memory for pipex");
        return (1);
    }
	ft_init_pipex(pipex);
	ft_check(argv, argc, pipex, envp);
	//ft_init(argv,argc);
	return (0);
}