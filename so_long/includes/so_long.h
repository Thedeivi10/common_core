/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:29:28 by davigome          #+#    #+#             */
/*   Updated: 2024/11/21 15:41:31 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define NAME "so_long"
# define TITRE "So Long"

//  ERROR MESSAGES//

# define E_FILENAME "The file is not a .ber file.\n"
# define E_NO_INIT "The map does not have a starting point.\n"
# define E_NO_EXIT "The map does not have an exit.\n"
# define E_NO_OBJ "The map does not have any collectible objects.\n"
# define E_MORE_INIT "The map has two or more starting points.\n"
# define E_MORE_EXIT "The map has two or more exits.\n"
# define E_NO_RECTAN "The map is not rectangular.\n"
# define E_NO_BLOCK "The map is not surrounded by walls.\n"
# define E_NO_PATH "There is no valid path in the map.\n"
# define E_CHAR "The map contains invalid characters.\n"
# define E_PLAYER "The map must contain one player.\n"
# define E_EMPTYLINE "The map contains one or more empty lines.\n"
# define E_NUMBER "The program must receive exactly one valid .ber file as an argmunet.\n"

// RETURN VALUES //
# define SUCCESS 0
# define FAILURE 1
# define ERROR -1
#endif