/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:34:51 by davigome          #+#    #+#             */
/*   Updated: 2024/04/26 14:15:02 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		cont_left;
	int		cont_right;
	char	*dest;
	int		i;
	int		j;
	
	
	cont_left = 0;
	cont_right = 0;
	i = -1;
	j = -1;
	if (!s1 || !set)
		return (NULL);
	while (s1[++i])
	{
		j = -1;
		while (set[++j])
			if(s1[i] == set[j])
			{
				cont_left++;
				break;
			}
		if (s1[i] != set[j])
			break;
	}
	i = ft_strlen(s1);
	while (s1[--i])
	{
		j = -1;
		while (set[++j])
			if (set[j] == s1[i])
			{
				cont_right++;
				break;
			}
		if (s1[i] != set[j])
			break;
	}
	dest = malloc(ft_strlen(s1) - cont_right - cont_left + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, &s1[cont_left],ft_strlen(s1) - cont_right - cont_left +1);
	dest[ft_strlen(s1) - cont_right - cont_left] = '\0';
	return (dest);
}

// int main (void)
// {
// 	char *s1 = "rt    t r t t t";

// 	printf("%s", ft_strtrim(s1, " rt "));
// 	return (0);
// }