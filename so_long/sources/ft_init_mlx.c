/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:31:20 by davigome          #+#    #+#             */
/*   Updated: 2024/11/27 11:46:41 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_mlx(t_map	*game)
{
	game->mlx = mlx_init(game->size.width * TILE_SIZE,
						 game->size.height * TILE_SIZE, TITRE, true);
	if (!game->mlx)
	{
		ft_printf("Error:\nCould not init MLX42");
		exit(ERROR);
	}
}